# notification :gntp, host: '192.168.1.7'
notification :gntp, host: '172.20.10.3'

guard 'rake', :task => 'test' do
  watch(%r{^test/(.+)\.rb$})
  watch(%r{^src/(.+)$})
end
