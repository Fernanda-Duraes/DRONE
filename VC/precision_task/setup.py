import os
from glob import glob
from setuptools import setup

package_name = 'precision_task'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'),
            glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='fernanda',
    maintainer_email='fernanda@example.com',
    description='No de visao computacional do trainee',
    license='MIT',
    entry_points={
        'console_scripts': [
            'trainee_vision_node = precision_task.trainee_vision_node:main',
        ],
    },
)
