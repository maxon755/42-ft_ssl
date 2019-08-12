#!/usr/bin/env python3

from unit_test import UnitTest

ut = UnitTest()

ft_ssl = './ft_ssl md5'
open_ssl = 'md5'
test_file = 'tests/test_file'

# Flag -s
ut.assertOutput(ft_ssl, open_ssl, '-s ""')
ut.assertOutput(ft_ssl, open_ssl, '-s "a"')
ut.assertOutput(ft_ssl, open_ssl, '-s "42"')
ut.assertOutput(ft_ssl, open_ssl, '-s "pity those that aren\'t following baerista on spotify."')

# Stdin
ut.assertOutput(ft_ssl, open_ssl, pipeIn='echo "pickle rick"')
ut.assertOutput(ft_ssl, open_ssl, '-p', 'echo "Do not pity the dead, Harry."')
ut.assertOutput(ft_ssl, open_ssl, ' -p ' + test_file, 'echo "be sure to handle edge cases carefully"')
ut.assertOutput(ft_ssl, open_ssl, pipeIn='cat ' + test_file)

# File
ut.assertOutput(ft_ssl, open_ssl, test_file)
ut.assertOutput(ft_ssl, open_ssl, '-r ' + test_file)

ut.assertOutputWithString(
	ft_ssl,
	'Pity the living.\ne20c3b973f63482a778f3fd1869b7f25\n',
	'-p -r',
	'echo "Pity the living."'
)

# Combo
ut.assertOutput(ft_ssl, open_ssl, '-p ' + test_file,  'echo "be sure to handle edge cases carefully"')
ut.assertOutput(ft_ssl, open_ssl, test_file,  'echo "some of this will not make sense at first"')
ut.assertOutput(ft_ssl, open_ssl, '-p -r ' + test_file,  'echo "but eventually you will understand"')

ut.assertOutput(ft_ssl, open_ssl, '-p -s "foo" ' + test_file,  'echo "GL HF let\'s go"')
ut.assertOutput(ft_ssl, open_ssl, '-r -p -s "foo" ' + test_file + ' -s "bar"',  'echo "one more thing"')
ut.assertOutput(ft_ssl, open_ssl, '-r -q -p -s "foo" ' + test_file,  'echo "just to be extra clear"')
