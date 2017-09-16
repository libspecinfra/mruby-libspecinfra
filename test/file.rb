b = Libspecinfra::Backend::Direct.new()
s = Libspecinfra::Specinfra.new(b)
f = s.file("/etc/passwd")

assert("file") do
  assert_equal(f.mode(), 0o644)
  assert_true(f.exist())
  assert_true(f.is_file())
  assert_false(f.is_directory())
  assert_false(f.is_block_device())
  assert_false(f.is_character_device())
  assert_false(f.is_pipe())
  assert_false(f.is_socket())
  assert_false(f.is_symlink())
  assert_true(f.contents().include?("root"))
  assert_equal(f.owner(), "root")
  assert_true(f.group() == "root" || f.group() == "wheel")
  assert_true(f.is_readable())
  assert_true(f.is_readable_by_owner())
  assert_true(f.is_readable_by_group())
  assert_true(f.is_readable_by_others())
  assert_true(f.is_readable_by_user("root"))
  assert_true(f.is_writable())
  assert_true(f.is_writable_by_owner())
  assert_false(f.is_writable_by_group())
  assert_false(f.is_writable_by_others())
  assert_true(f.is_writable_by_user("root"))
  assert_equal(f.md5sum().size(), 32)
end
