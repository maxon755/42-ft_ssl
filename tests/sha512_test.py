#!/usr/bin/env python3

from unit_test import UnitTest

ut = UnitTest()

ft_ssl = './ft_ssl sha512'
test_file = 'tests/test_file'

# Common
ut.assertOutputWithString(
	ft_ssl,
	'usage: sha512 [-pqrh] [-s string] [files ...]\n' +
	'       use -h for help\n',
	'-x',
)
ut.assertOutputWithString(
	ft_ssl,
'''Secure Hash Algorithm Version 2
usage: sha512 [-pqrh] [-s string] [files ...]
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
	'SHA512 ("") = cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e\n',
	'-s ""'
)
ut.assertOutputWithString(ft_ssl,
	'SHA512 ("a") = 1f40fc92da241694750979ee6cf582f2d5d7d28e18335de05abc54d0560e0f5302860c652bf08d560252aa5e74210546f369fbbbce8c12cfc7957b2652fe9a75\n',
	'-s "a"'
)
ut.assertOutputWithString(ft_ssl,
	'SHA512 ("42") = 39ca7ce9ecc69f696bf7d20bb23dd1521b641f806cc7a6b724aaa6cdbffb3a023ff98ae73225156b2c6c9ceddbfc16f5453e8fa49fc10e5d96a3885546a46ef4\n',
	'-s "42"'
)
ut.assertOutputWithString(ft_ssl,
	'SHA512 ("pity those that aren\'t following baerista on spotify.") ' +
	'= c06dd99415006509229a70c60d41b28b6138217551d195fbd6135ac8afcec0d7e050f2470c855ba1b9155cd7b7c74b27f7f15cee9f16912613f5b88ec109ff1f\n',
	'-s "pity those that aren\'t following baerista on spotify."'
)

# # Stdin
ut.assertOutputWithString(ft_ssl,
	'1d1a1921d70a90b7c984a4a36370aaf7d699faa516a00c6f828439a99b8c949733cde9e2c578b39f084440363532e85bd5705b7141077c4661655d700092e6c4\n',
	pipeIn='echo "pickle rick"'
)
ut.assertOutputWithString(ft_ssl,
	'Do not pity the dead, Harry.\n' +
	'cbbb5025780ff59bde8a3e7fd493c61da587441c4f16225e43d3f5c4770656ae3e8701c2e4c63d06cd2fbde36702008cfc0c109dbea88f4798401bab4be1e3fb\n',
	'-p',
	'echo "Do not pity the dead, Harry."'
)
ut.assertOutputWithString(ft_ssl,
	'4652fbb98fb2706702dcce8d7a0c24c0443e43c0e9845ad700ffbd9c1ce0b0b712fc362efdbd2ff0756b857c4a79eb089ca3698cd0ec5dafdd9b6602d922616d\n',
	pipeIn='cat ' + test_file
)
ut.assertOutputWithString(
	ft_ssl,
	'Pity the living.\n' +
	'eeff6ebf504b8c42ac83af9ca87096703946dd42fc93015c37bfe801c3539307e7659fa3ded3c982e38d26b960c153b8de6bd3b55dfdf488eda506a2e01b8b96\n',
	'-p -r',
	'echo "Pity the living."'
)


# # File
ut.assertOutputWithString(ft_ssl,
	'SHA512 (tests/test_file) = 4652fbb98fb2706702dcce8d7a0c24c0443e43c0e9845ad700ffbd9c1ce0b0b712fc362efdbd2ff0756b857c4a79eb089ca3698cd0ec5dafdd9b6602d922616d\n',
	test_file
)
ut.assertOutputWithString(ft_ssl,
	'4652fbb98fb2706702dcce8d7a0c24c0443e43c0e9845ad700ffbd9c1ce0b0b712fc362efdbd2ff0756b857c4a79eb089ca3698cd0ec5dafdd9b6602d922616d tests/test_file\n',
	'-r ' + test_file
)

# # Combo
ut.assertOutputWithString(ft_ssl,
	'be sure to handle edge cases carefully\n' +
	'352cdbc6c6f4fc47032f36786f182ba58a42bcf35a06b39a646b59e640b98335eb07a9bbd03e9859a8eaae2f148a1b528a7c236db0d9599d41e05f16ddf235ab\n' +
	'SHA512 (tests/test_file) = 4652fbb98fb2706702dcce8d7a0c24c0443e43c0e9845ad700ffbd9c1ce0b0b712fc362efdbd2ff0756b857c4a79eb089ca3698cd0ec5dafdd9b6602d922616d\n',
	' -p ' + test_file, 'echo "be sure to handle edge cases carefully"'
)
ut.assertOutputWithString(ft_ssl,
	'SHA512 (tests/test_file) = 4652fbb98fb2706702dcce8d7a0c24c0443e43c0e9845ad700ffbd9c1ce0b0b712fc362efdbd2ff0756b857c4a79eb089ca3698cd0ec5dafdd9b6602d922616d\n',
	test_file,
	'echo "some of this will not make sense at first"'
)
ut.assertOutputWithString(ft_ssl,
	'but eventually you will understand\n' +
	'a7ffee36cc2fc95f6880b7e9c137eadee67cf07c0e89b7d2acfafa9d3a95ba2c5cffc7e2cb068fe51c37edaf569d4397564863c0ca95484bae0959ed31b541d4\n' +
	'4652fbb98fb2706702dcce8d7a0c24c0443e43c0e9845ad700ffbd9c1ce0b0b712fc362efdbd2ff0756b857c4a79eb089ca3698cd0ec5dafdd9b6602d922616d tests/test_file\n',
	'-p -r ' + test_file,  'echo "but eventually you will understand"'
)

ut.assertOutputWithString(ft_ssl,
	'GL HF let\'s go\n' +
	'ace7a0d8f8d5907452c4d4b5a9d5699de6e75b0263dafe5e0a7b30ef50e4be20a108db78ec2218434bd913ffdff26fa1c3d0e2a15d08fc1d113315e506de8a39\n' +
	'SHA512 ("foo") = f7fbba6e0636f890e56fbbf3283e524c6fa3204ae298382d624741d0dc6638326e282c41be5e4254d8820772c5518a2c5a8c0c7f7eda19594a7eb539453e1ed7\n' +
	'SHA512 (tests/test_file) = 4652fbb98fb2706702dcce8d7a0c24c0443e43c0e9845ad700ffbd9c1ce0b0b712fc362efdbd2ff0756b857c4a79eb089ca3698cd0ec5dafdd9b6602d922616d\n',
	'-p -s "foo" ' + test_file,
	'echo "GL HF let\'s go"'
)

ut.assertOutputWithString(ft_ssl,
	'one more thing\n' +
	'a440177c36cfca4ca61f4e380fe69eec8a5fbbac34d21e0e1c403cfa68c980055b0bf0c7cdc8d2e7154f3959dbcfa86ec4e8503f7b3bf420ce29936947f61924\n' +
	'f7fbba6e0636f890e56fbbf3283e524c6fa3204ae298382d624741d0dc6638326e282c41be5e4254d8820772c5518a2c5a8c0c7f7eda19594a7eb539453e1ed7 "foo"\n' +
	'4652fbb98fb2706702dcce8d7a0c24c0443e43c0e9845ad700ffbd9c1ce0b0b712fc362efdbd2ff0756b857c4a79eb089ca3698cd0ec5dafdd9b6602d922616d tests/test_file\n',
	'-r -p -s "foo" ' + test_file + ' -s "bar"',
	'echo "one more thing"'
)

ut.assertOutputWithString(ft_ssl,
	'just to be extra clear\n' +
	'b865829a32dcfb9c72ef467ea2619d1aa26ae89d053a9f866e843ac4b46f47f59f9b867afdb6574319b16b7ee7ec8961dda61ce486afc4a4e9f32ad1335774cb\n' +
	'f7fbba6e0636f890e56fbbf3283e524c6fa3204ae298382d624741d0dc6638326e282c41be5e4254d8820772c5518a2c5a8c0c7f7eda19594a7eb539453e1ed7\n' +
	'4652fbb98fb2706702dcce8d7a0c24c0443e43c0e9845ad700ffbd9c1ce0b0b712fc362efdbd2ff0756b857c4a79eb089ca3698cd0ec5dafdd9b6602d922616d\n',
	'-r -q -p -s "foo" ' + test_file, 'echo "just to be extra clear"'
)