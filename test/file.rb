b = Libspecinfra::Backend::Direct.new()
s = Libspecinfra::Specinfra.new(b)
f = s.file("/etc/passwd")

assert("file") do
  assert_equal(f.mode(), 0o644)
end









