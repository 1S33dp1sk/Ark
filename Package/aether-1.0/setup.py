from setuptools import setup

setup(
	name='dev3',
	version='0.1.1',
	packages=['dev3','dev3/configs','dev3/errors','dev3/interactions','dev3/logging','dev3/triggers','dev3/utils'],
    install_requires=['dataclasses','functools','copy','json','re','web3','asyncio','inspect']
)

