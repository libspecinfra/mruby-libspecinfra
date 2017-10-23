b = Libspecinfra::Backend::Direct.new()
s = Libspecinfra::Specinfra.new(b)

assert("nginx") do
  nginx = s.service("nginx")

  if ENV['TEST_SERVICE']
    assert_true(nginx.is_running())
  end
end
