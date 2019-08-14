#!/usr/bin/env python3

from unit_test import UnitTest

ut = UnitTest()

ft_ssl = './ft_ssl'
test_file = 'tests/test_file'

# Flag -s
ut.assertOutputWithString(ft_ssl,
	'usage: ft_ssl command [command opts] [command args]\n',
)
ut.assertOutputWithString(ft_ssl,
'''ft_ssl: Error: md6 is an invalid command.

Standard commands:

Message Digest commands:
md5
sha224
sha256
sha384
sha512

Cipher commands:
''',
	'md6'
)