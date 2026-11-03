from setuptools import find_packages
from setuptools import setup

setup(
    name='precision_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('precision_interfaces', 'precision_interfaces.*')),
)
