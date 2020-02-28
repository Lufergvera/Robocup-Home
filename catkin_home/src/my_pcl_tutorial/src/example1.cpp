#include <ProcessingCloud.h>
class segmentation {

public:

  explicit segmentation(ros::NodeHandle nh) : m_nh(nh)  {
    // define the subscriber and publisher
    m_sub = m_nh.subscribe ("/camera/depth/color/points", 1, &segmentation::cloud_cb, this);
    m_clusterPub = m_nh.advertise<my_pcl_tutorial::SegmentedClustersArray> ("pcl_clusters",1);
    m_pub = m_nh.advertise<sensor_msgs::PointCloud2> ("output",1);

  }

private:

ros::NodeHandle m_nh;
ros::Publisher m_pub;
ros::Subscriber m_sub;
ros::Publisher m_clusterPub;

void cloud_cb(const sensor_msgs::PointCloud2ConstPtr& input);

}; // end class definition
void segmentation::cloud_cb (const sensor_msgs::PointCloud2ConstPtr& input){
  // ... do data processing
  sensor_msgs::PointCloud2 output;
  pcl::PCLPointCloud2 outputPCL;
  // Container for original & filtered data
  pcl::PCLPointCloud2::Ptr cloudorigin(new pcl::PCLPointCloud2);
  pcl::PCLPointCloud2::Ptr cloud_filtered (new pcl::PCLPointCloud2);

  //pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
  //pcl::PCLPointCloud2 cloud_filtered;
  // Convert to PCL data type
  pcl_conversions::toPCL(*input, *cloudorigin);
    // Perform the actual filtering
  pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
  sor.setInputCloud (cloudorigin);
  sor.setLeafSize (0.01, 0.01, 0.01);
  sor.filter (*cloud_filtered);

  pcl::PCLPointCloud2::Ptr cloud_filtered2 (new pcl::PCLPointCloud2);
  pcl::PassThrough<pcl::PCLPointCloud2> pass2;
  pass2.setInputCloud(cloud_filtered);
  pass2.setFilterFieldName("z");
  pass2.setFilterLimits(0.2,1.5);
  pass2.filter(*cloud_filtered2);

  pcl::PointCloud<pcl::PointXYZRGB>::Ptr temp(new pcl::PointCloud<pcl::PointXYZRGB>);
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr PlannedCloud(new pcl::PointCloud<pcl::PointXYZRGB>);
  double zplanee=0;
  pcl::fromPCLPointCloud2(*cloud_filtered2, *temp);
  PlannedCloud=PlanarRANSAC(temp,zplanee);
  my_pcl_tutorial::SegmentedClustersArray CloudClusters1;
  CloudClusters1=Clustering(PlannedCloud);

  pcl::toPCLPointCloud2( *PlannedCloud , outputPCL);
  // Convert to ROS data type
  pcl_conversions::fromPCL(outputPCL, output);
  // Publish the data
  m_pub.publish (output);
  m_clusterPub.publish(CloudClusters1);

} 
int
main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "my_pcl_tutorial");
  ros::NodeHandle nh;

  segmentation segs(nh);

  // Create a ROS publisher for the output point cloud

  // Spin
  ros::spin ();
}
