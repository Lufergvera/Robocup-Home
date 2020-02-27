#!/usr/bin/env python

# DESCRIPTION
from intercom.msg import action_selector_cmd
import time
from threading import Thread
import rospy
import csv
import os
from action_knight import ActionKnight

"""
	TODO: Define description
"""

# TOPICS PUBLISHED
"""
    NA
"""

# TOPICS READ
"""
    engine_commands -> String
"""

# MSG USED
"""
    action_selector_msg -> 
       Header header
       string intent
       string[] args
"""

isActionQueueChanged = True
actionQueue = []

class Main_Engine(object):
    def __init__(self,filename):
        self.possible_actions = self.loadActions(filename)
        print(self.possible_actions)

    def loadActions(self,filename):
        '''
        Returns a dictionary with the possible actions defined in the csv file
        {
            cmd_id:{cmd_category,cmd_priority,require_args}
        }
        '''
        directory = os.path.dirname(os.path.realpath(__file__))
        absolute_path_to_csv = os.path.join(directory,filename)
        print("Opening possible actions: "+absolute_path_to_csv)
        dictionary_possible_actions = dict()
        with open(absolute_path_to_csv,'r') as action_file:
            dict_reader = csv.DictReader(action_file)
            for row in dict_reader:
                cmd_id = row.get('cmd_id')
                del row['cmd_id']
                dictionary_possible_actions[cmd_id] = dict(row)
        return dictionary_possible_actions

    def shutdown_callback(self):
        print("CRITICAL -------------Shutting down main_engine--------------")
    
    
    def new_action_callback(self, msg):
        print("A new action is triggered")
        print(msg.intent)
        print(msg.args)

    def decide_if_priority(self,new_action_id):

def listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    FILENAME_OF_CSV = 'possible_actions.csv'
    main_engine = Main_Engine(FILENAME_OF_CSV)

    rospy.init_node('engine', anonymous=False)
    rospy.on_shutdown(main_engine.shutdown_callback)
    rospy.Subscriber("action_requested", action_selector_cmd, main_engine.new_action_callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()


if __name__ == '__main__':
    listener()
