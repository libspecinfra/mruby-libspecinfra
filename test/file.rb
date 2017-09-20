b = Libspecinfra::Backend::Direct.new()
s = Libspecinfra::Specinfra.new(b)

assert("/etc/asswd") do
  f = s.file("/etc/passwd")

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
  assert_equal(f.sha256sum().size(), 64)
  assert_true(f.size() > 0)
end

assert("file link") do
  f = s.file("/etc")
  if f.exist() && f.is_symlink()
    assert_equal(f.linked_to(), "private/etc")
  end

  f = s.file("/var/lock")
  if f.exist() && f.is_symlink()
    assert_equal(f.linked_to(), "/run/lock")
  end
end

assert("file does not exist") do
  f = s.file("no_existent_file")

  assert_false(f.exist())
  assert_raise(RuntimeError, "entity not found") { f.mode() }
  assert_raise(RuntimeError, "entity not found") { f.is_file() }
end
