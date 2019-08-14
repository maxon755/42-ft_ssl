#!/usr/bin/env python3

from unit_test import UnitTest

ut = UnitTest()

ft_ssl = './ft_ssl md5'
open_ssl = 'md5'
test_file = 'tests/test_file'

# Common
ut.assertOutputWithString(
	ft_ssl,
	'usage: md5 [-pqrh] [-s string] [files ...]\n' +
	'       use -h for help\n',
	'-x',
)
ut.assertOutputWithString(
	ft_ssl,
'''Message Digest 5
usage: md5 [-pqrh] [-s string] [files ...]
  -p, echo STDIN to STDOUT and append the checksum to STDOUT
  -q, quiet mode
  -r, reverse the format of the output
  -s, print the sum of the given string
  -h, help
''',
	'-h',
)

# Flag -s
ut.assertOutput(ft_ssl, open_ssl, '-s ""')
ut.assertOutput(ft_ssl, open_ssl, '-s "a"')
ut.assertOutput(ft_ssl, open_ssl, '-s "42"')
ut.assertOutput(ft_ssl, open_ssl, '-s "pity those that aren\'t following baerista on spotify."')

# Stdin
ut.assertOutput(ft_ssl, open_ssl, pipeIn='echo "pickle rick"')
ut.assertOutput(ft_ssl, open_ssl, '-p', 'echo "Do not pity the dead, Harry."')
ut.assertOutput(ft_ssl, open_ssl, pipeIn='cat ' + test_file)
ut.assertOutputWithString(
	ft_ssl,
	'Pity the living.\n' +
	'e20c3b973f63482a778f3fd1869b7f25\n',
	'-p -r',
	'echo "Pity the living."'
)

# File
ut.assertOutput(ft_ssl, open_ssl, test_file)
ut.assertOutput(ft_ssl, open_ssl, '-r ' + test_file)

# Combo
ut.assertOutput(ft_ssl, open_ssl, '-p ' + test_file, 'echo "be sure to handle edge cases carefully"')
ut.assertOutput(ft_ssl, open_ssl, test_file, 'echo "some of this will not make sense at first"')
ut.assertOutput(ft_ssl, open_ssl, '-p -r ' + test_file, 'echo "but eventually you will understand"')

ut.assertOutput(ft_ssl, open_ssl, '-p -s "foo" ' + test_file, 'echo "GL HF let\'s go"')
ut.assertOutput(ft_ssl, open_ssl, '-r -p -s "foo" ' + test_file + ' -s "bar"', 'echo "one more thing"')
ut.assertOutput(ft_ssl, open_ssl, '-r -q -p -s "foo" ' + test_file, 'echo "just to be extra clear"')
