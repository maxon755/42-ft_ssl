#!/usr/bin/env python3

from unit_test import UnitTest

ut = UnitTest()

ft_ssl = './ft_ssl sha224'
test_file = 'tests/test_file'

# Common
ut.assertOutputWithString(
	ft_ssl,
	'usage: sha224 [-pqrh] [-s string] [files ...]\n' +
	'       use -h for help\n',
	'-x',
)
ut.assertOutputWithString(
	ft_ssl,
'''Secure Hash Algorithm Version 2
usage: sha224 [-pqrh] [-s string] [files ...]
  -p, echo STDIN to STDOUT and append the checksum to STDOUT
  -q, quiet mode
  -r, reverse the format of the output
  -s, print the sum of the given string
  -h, help
''',
	'-h',
)

# Flag -s
ut.assertOutputWithString(ft_ssl,
	'SHA224 ("") = d14a028c2a3a2bc9476102bb288234c415a2b01f828ea62ac5b3e42f\n',
	'-s ""'
)
ut.assertOutputWithString(ft_ssl,
	'SHA224 ("a") = abd37534c7d9a2efb9465de931cd7055ffdb8879563ae98078d6d6d5\n',
	'-s "a"'
)
ut.assertOutputWithString(ft_ssl,
	'SHA224 ("42") = 3d24353c0d9d445310597750ba9d4d4f3dcf7940eeb57ccd7fa70b3e\n',
	'-s "42"'
)
ut.assertOutputWithString(ft_ssl,
	'SHA224 ("pity those that aren\'t following baerista on spotify.") ' +
	'= d5e856b036047b934a393487121d5981a2cfb0fa6b97d0e66f2b42cf\n',
	'-s "pity those that aren\'t following baerista on spotify."'
)

# # Stdin
ut.assertOutputWithString(ft_ssl,
	'e4529dbc55d6e02a6a135896dd0a50435fcd1a4240a376e3c7805de3\n',
	pipeIn='echo "pickle rick"'
)
ut.assertOutputWithString(ft_ssl,
	'Do not pity the dead, Harry.\n' +
	'7bba6e0dea06e9a4e5ccef4778f92a6e313dd04ef6404d5275dcea07\n',
	'-p',
	'echo "Do not pity the dead, Harry."'
)
ut.assertOutputWithString(ft_ssl,
	'4071b20c13752233693d28cc51a4056772aa745d8032b0c3bcb82faf\n',
	pipeIn='cat ' + test_file
)
ut.assertOutputWithString(
	ft_ssl,
	'Pity the living.\n' +
	'fa52b99972cdcfbf27c3968fa06b87249f4bfe29e53bc6988ae09c88\n',
	'-p -r',
	'echo "Pity the living."'
)


# # File
ut.assertOutputWithString(ft_ssl,
	'SHA224 (tests/test_file) = 4071b20c13752233693d28cc51a4056772aa745d8032b0c3bcb82faf\n',
	test_file
)
ut.assertOutputWithString(ft_ssl,
	'4071b20c13752233693d28cc51a4056772aa745d8032b0c3bcb82faf tests/test_file\n',
	'-r ' + test_file
)

# # Combo
ut.assertOutputWithString(ft_ssl,
	'be sure to handle edge cases carefully\n' +
	'79b7fe4a7c8ac818cc9f136ec1f13012eed0f5888b1895f9c77b1235\n' +
	'SHA224 (tests/test_file) = 4071b20c13752233693d28cc51a4056772aa745d8032b0c3bcb82faf\n',
	' -p ' + test_file, 'echo "be sure to handle edge cases carefully"'
)
ut.assertOutputWithString(ft_ssl,
	'SHA224 (tests/test_file) = 4071b20c13752233693d28cc51a4056772aa745d8032b0c3bcb82faf\n',
	test_file,
	'echo "some of this will not make sense at first"'
)
ut.assertOutputWithString(ft_ssl,
	'but eventually you will understand\n' +
	'612ba055b3238f7b04113778d77884cba7e362369516f78e5c1497c0\n' +
	'4071b20c13752233693d28cc51a4056772aa745d8032b0c3bcb82faf tests/test_file\n',
	'-p -r ' + test_file,  'echo "but eventually you will understand"'
)

ut.assertOutputWithString(ft_ssl,
	'GL HF let\'s go\n' +
	'65b713885260f441ca866252487e8aa66094f6c20a7b985685b5d829\n' +
	'SHA224 ("foo") = 0808f64e60d58979fcb676c96ec938270dea42445aeefcd3a4e6f8db\n' +
	'SHA224 (tests/test_file) = 4071b20c13752233693d28cc51a4056772aa745d8032b0c3bcb82faf\n',
	'-p -s "foo" ' + test_file,
	'echo "GL HF let\'s go"'
)

ut.assertOutputWithString(ft_ssl,
	'one more thing\n' +
	'1efb20ffc3829a7455c089403bf312d538a8e2e5fb9270dc9fe92314\n' +
	'0808f64e60d58979fcb676c96ec938270dea42445aeefcd3a4e6f8db "foo"\n' +
	'4071b20c13752233693d28cc51a4056772aa745d8032b0c3bcb82faf tests/test_file\n',
	'-r -p -s "foo" ' + test_file + ' -s "bar"',
	'echo "one more thing"'
)

ut.assertOutputWithString(ft_ssl,
	'just to be extra clear\n' +
	'00e44d133c4c26ca5aa52342d5238301641ce99d2850cf6fd3bc9918\n' +
	'0808f64e60d58979fcb676c96ec938270dea42445aeefcd3a4e6f8db\n' +
	'4071b20c13752233693d28cc51a4056772aa745d8032b0c3bcb82faf\n',
	'-r -q -p -s "foo" ' + test_file, 'echo "just to be extra clear"'
)