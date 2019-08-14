#!/usr/bin/env python3

from unit_test import UnitTest

ut = UnitTest()

ft_ssl = './ft_ssl sha384'
test_file = 'tests/test_file'

# Flag -s
ut.assertOutputWithString(ft_ssl,
	'SHA384 ("") = 38b060a751ac96384cd9327eb1b1e36a21fdb71114be07434c0cc7bf63f6e1da274edebfe76f65fbd51ad2f14898b95b\n',
	'-s ""'
)
ut.assertOutputWithString(ft_ssl,
	'SHA384 ("a") = 54a59b9f22b0b80880d8427e548b7c23abd873486e1f035dce9cd697e85175033caa88e6d57bc35efae0b5afd3145f31\n',
	'-s "a"'
)
ut.assertOutputWithString(ft_ssl,
	'SHA384 ("42") = 8f5e4d4e4972d73670383f94f727e58e683b6397b284c6493fab2754882f5e0847a359a67df5b6c91d3858a81e42e252\n',
	'-s "42"'
)
ut.assertOutputWithString(ft_ssl,
	'SHA384 ("pity those that aren\'t following baerista on spotify.") ' +
	'= c49e5969a1679e33a88260dd8d22218d93498c8e096b7b3a49c3a5c25f80a27d765ba7830a507eb8c2949c97941a8db6\n',
	'-s "pity those that aren\'t following baerista on spotify."'
)

# Stdin
ut.assertOutputWithString(ft_ssl,
	'08c3f5ba57482ea5f8478d79800d6647a800f1deaeede53a5a794a151e8ee27670a2c7bd9ad6c83e468801614eac4780\n',
	pipeIn='echo "pickle rick"'
)
ut.assertOutputWithString(ft_ssl,
	'Do not pity the dead, Harry.\n' +
	'bda4eacfcc92434bbc8d914234919ef6af9c89916d3e58c4da7cb2d9c316ffab8e506d48ea317c7c044705b2378f9707\n',
	'-p',
	'echo "Do not pity the dead, Harry."'
)
ut.assertOutputWithString(ft_ssl,
	'e696b6db65f90461c7798ecd80d0dc4bf6aad648e576a31c6c5d168aa22d631ddf42d7dc5e860c96944644eca48dec6b\n',
	pipeIn='cat ' + test_file
)
ut.assertOutputWithString(
	ft_ssl,
	'Pity the living.\n' +
	'7629e1b277eaa39453b47fe9cb4789da57cab72d71a06d312ad9685e7b3e87b0b28a6d184fd5e3c4bb7cc6546baebb01\n',
	'-p -r',
	'echo "Pity the living."'
)


# File
ut.assertOutputWithString(ft_ssl,
	'SHA384 (tests/test_file) = e696b6db65f90461c7798ecd80d0dc4bf6aad648e576a31c6c5d168aa22d631ddf42d7dc5e860c96944644eca48dec6b\n',
	test_file
)
ut.assertOutputWithString(ft_ssl,
	'e696b6db65f90461c7798ecd80d0dc4bf6aad648e576a31c6c5d168aa22d631ddf42d7dc5e860c96944644eca48dec6b tests/test_file\n',
	'-r ' + test_file
)

# # # Combo
ut.assertOutputWithString(ft_ssl,
	'be sure to handle edge cases carefully\n' +
	'22a9126bd5629476e871bd01f7e3f5389ad6c8190bc0b01866d97a5fe35434f7810334b8f30ea6771e1733939071e33f\n' +
	'SHA384 (tests/test_file) = e696b6db65f90461c7798ecd80d0dc4bf6aad648e576a31c6c5d168aa22d631ddf42d7dc5e860c96944644eca48dec6b\n',
	' -p ' + test_file, 'echo "be sure to handle edge cases carefully"'
)
ut.assertOutputWithString(ft_ssl,
	'SHA384 (tests/test_file) = e696b6db65f90461c7798ecd80d0dc4bf6aad648e576a31c6c5d168aa22d631ddf42d7dc5e860c96944644eca48dec6b\n',
	test_file,
	'echo "some of this will not make sense at first"'
)
ut.assertOutputWithString(ft_ssl,
	'but eventually you will understand\n' +
	'b7f082b516e8ca30aff209862b58dbb6b03adbb9783f2d5fb58c13ccf4afed2ea008cff895cdf106be4d6972832b4d5f\n' +
	'e696b6db65f90461c7798ecd80d0dc4bf6aad648e576a31c6c5d168aa22d631ddf42d7dc5e860c96944644eca48dec6b tests/test_file\n',
	'-p -r ' + test_file,  'echo "but eventually you will understand"'
)

ut.assertOutputWithString(ft_ssl,
	'GL HF let\'s go\n' +
	'449462a4bd60b393f165ef68a10b829b33bef50086d9ef5b0b9dd06f1be50425edcbecac9a231dfaa4ca56a227beaff3\n' +
	'SHA384 ("foo") = 98c11ffdfdd540676b1a137cb1a22b2a70350c9a44171d6b1180c6be5cbb2ee3f79d532c8a1dd9ef2e8e08e752a3babb\n' +
	'SHA384 (tests/test_file) = e696b6db65f90461c7798ecd80d0dc4bf6aad648e576a31c6c5d168aa22d631ddf42d7dc5e860c96944644eca48dec6b\n',
	'-p -s "foo" ' + test_file,
	'echo "GL HF let\'s go"'
)

ut.assertOutputWithString(ft_ssl,
	'one more thing\n' +
	'52f195be7acd427a06f8a2527156455791454fe7ee026240fe7d75b5a53d28ee90cbfa0a166aad2e7f30c8f653bdd357\n' +
	'98c11ffdfdd540676b1a137cb1a22b2a70350c9a44171d6b1180c6be5cbb2ee3f79d532c8a1dd9ef2e8e08e752a3babb "foo"\n' +
	'e696b6db65f90461c7798ecd80d0dc4bf6aad648e576a31c6c5d168aa22d631ddf42d7dc5e860c96944644eca48dec6b tests/test_file\n',
	'-r -p -s "foo" ' + test_file + ' -s "bar"',
	'echo "one more thing"'
)

ut.assertOutputWithString(ft_ssl,
	'just to be extra clear\n' +
	'8ca98065d6aef14c6ac950d95d9998a7f882716094fa19f232c387b35f5e25a03cf934bcd4ba23e8c6286dbad00df4d8\n' +
	'98c11ffdfdd540676b1a137cb1a22b2a70350c9a44171d6b1180c6be5cbb2ee3f79d532c8a1dd9ef2e8e08e752a3babb\n' +
	'e696b6db65f90461c7798ecd80d0dc4bf6aad648e576a31c6c5d168aa22d631ddf42d7dc5e860c96944644eca48dec6b\n',
	'-r -q -p -s "foo" ' + test_file, 'echo "just to be extra clear"'
)