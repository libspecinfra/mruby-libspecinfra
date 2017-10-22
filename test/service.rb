b = Libspecinfra::Backend::Direct.new()
s = Libspecinfra::Specinfra.new(b)

assert("nginx") do
  nginx = s.service("nginx")

end
