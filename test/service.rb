b = Libspecinfra::Backend::Direct.new()
s = Libspecinfra::Specinfra.new(b)

assert("nginx") do
  dbus = s.service("dbus")
  sshd = s.service("sshd")
  nginx = s.service("nginx")

  if ENV['TEST_SERVICE']
    assert_true(dbus.is_running())
    assert_true(sshd.is_enabled())

    assert_true(nginx.enable())
    assert_true(nginx.is_enabled())

    assert_true(nginx.is_running())
  end
end
