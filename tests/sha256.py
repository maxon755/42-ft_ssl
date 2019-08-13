#!/usr/bin/env python3

from unit_test import UnitTest

ut = UnitTest()

ft_ssl = './ft_ssl sha256'
test_file = 'tests/test_file'

# Flag -s
ut.assertOutputWithString(ft_ssl,
	'SHA256 ("") = e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855\n',
	'-s ""'
)
ut.assertOutputWithString(ft_ssl,
	'SHA256 ("a") = ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb\n',
	'-s "a"'
)
ut.assertOutputWithString(ft_ssl,
	'SHA256 ("42") = 73475cb40a568e8da8a045ced110137e159f890ac4da883b6b17dc651b3a8049\n',
	'-s "42"'
)
ut.assertOutputWithString(ft_ssl,
	'SHA256 ("pity those that aren\'t following baerista on spotify.") ' +
	'= 7838c25c9debff86c584245d67b429186d3850c89da31c0b49b8d0380a3e14bf\n',
	'-s "pity those that aren\'t following baerista on spotify."'
)

# Stdin
ut.assertOutputWithString(ft_ssl,
	'a9c55180c67a4bc62753d836843f46fa47af28874600cdc637de921d711937ed\n',
	pipeIn='echo "pickle rick"'
)
ut.assertOutputWithString(ft_ssl,
	'Do not pity the dead, Harry.\n' +
	'7197000d32ca5a13cf923ba196286a72daa06e9f168c4dd5753f917568ea373f\n',
	'-p',
	'echo "Do not pity the dead, Harry."'
)
ut.assertOutputWithString(ft_ssl,
	'f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705\n',
	pipeIn='cat ' + test_file
)
ut.assertOutputWithString(
	ft_ssl,
	'Pity the living.\n' +
	'40133cfe543247c1cae0ffb0003c1179ce9fb0046bee19f9fca167380643ba45\n',
	'-p -r',
	'echo "Pity the living."'
)


# File
ut.assertOutputWithString(ft_ssl,
	'SHA256 (tests/test_file) = f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705\n',
	test_file
)
ut.assertOutputWithString(ft_ssl,
	'f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705 tests/test_file\n',
	'-r ' + test_file
)

# Combo
ut.assertOutputWithString(ft_ssl,
	'be sure to handle edge cases carefully\n' +
	'ef9241f878a1da676104a81239792a2817bc0390a427ca20bad1a59030fd20c2\n' +
	'SHA256 (tests/test_file) = f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705\n',
	' -p ' + test_file, 'echo "be sure to handle edge cases carefully"')
ut.assertOutputWithString(ft_ssl,
	'SHA256 (tests/test_file) = f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705\n',
	test_file,
	'echo "some of this will not make sense at first"'
)
ut.assertOutputWithString(ft_ssl,
	'but eventually you will understand\n' +
	'43da940057fd3b7453ee91b3a056a41343e6f0bce315570ed27e06c993a539da\n' +
	'f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705 tests/test_file\n',
	'-p -r ' + test_file,  'echo "but eventually you will understand"')

ut.assertOutputWithString(ft_ssl,
	'GL HF let\'s go\n' +
	'f33201f3d70c9dccccec022e2ff0df2006e016f153f600407917d14955fbec22\n' +
	'SHA256 ("foo") = 2c26b46b68ffc68ff99b453c1d30413413422d706483bfa0f98a5e886266e7ae\n' +
	'SHA256 (tests/test_file) = f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705\n',
	'-p -s "foo" ' + test_file,
	'echo "GL HF let\'s go"'
)

ut.assertOutputWithString(ft_ssl,
	'one more thing\n' +
	'720bbf63077e0bea3b70c87954123daa6fcf32f973f4d646622bd016b140ec75\n' +
	'2c26b46b68ffc68ff99b453c1d30413413422d706483bfa0f98a5e886266e7ae "foo"\n' +
	'f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705 tests/test_file\n',
	'-r -p -s "foo" ' + test_file + ' -s "bar"',
	'echo "one more thing"'
)

ut.assertOutputWithString(ft_ssl,
	'just to be extra clear\n' +
	'41c3da28172faf72bb777d6a428b6d801427d02513c56cd9e3672f44383f8eee\n' +
	'2c26b46b68ffc68ff99b453c1d30413413422d706483bfa0f98a5e886266e7ae\n' +
	'f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705\n',
	'-r -q -p -s "foo" ' + test_file, 'echo "just to be extra clear"')