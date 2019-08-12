#!/usr/bin/env python3

import os

class UnitTest():
	def __init__(self):
		pass

	def __executeCommand(self, command):
		return os.popen(command).read()

	def printSuccess(self, command1, command2='', output=''):
		print('\033[92m' + "{}\n{}\n{}".format(command1, command2, output) + '\033[37m')

	def printFailed(self, command1, command2='', out1='', out2=''):
		print('\033[31m')
		print ('{}\n{}'.format(command1, out1))
		print ('{}\n{}'.format(command2, out2))
		exit()

	def assertOutput(self, bin1, bin2, args='', pipeIn=''):
		command1 = (pipeIn + ' | ' if pipeIn else '') + bin1 + ' ' + args
		command2 = (pipeIn + ' | ' if pipeIn else '') + bin2 + ' ' + args

		out1 = self.__executeCommand(command1)
		out2 = self.__executeCommand(command2)

		if (out1 == out2):
			self.printSuccess(command1, command2, out1)
		else:
			self.printFailed(command1, command2, out1, out2)

	def assertOutputWithString(self, bin1, string, args='', pipeIn=''):
		command = (pipeIn + ' | ' if pipeIn else '') + bin1 + ' ' + args
		out = self.__executeCommand(command)
		if (out == string):
			self.printSuccess(command, string, out)
		else:
			self.printFailed(command, out1=out, out2=string)
