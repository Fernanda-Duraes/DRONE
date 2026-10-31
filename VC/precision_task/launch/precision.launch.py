# Copyright 2026 AVANT Trainee Team

from launch import LaunchDescription
from launch_ros.actions import Node

package_name = 'precision_task'


def generate_launch_description():

    return LaunchDescription(
        [
            Node(
                package=package_name,
                executable="simulation_node",
                name="simulation_node",
                output="screen",
            ),
            Node(
                package=package_name,
                executable="trainee_vision_node",
                name="task",
                output="screen",
            ),

        ]
    )
