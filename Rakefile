MRUBY_CONFIG=File.expand_path(ENV["MRUBY_CONFIG"] || ".travis-build_config.rb")
MRUBY_VERSION=ENV["MRUBY_VERSION"] || "master"

file :mruby do
  cmd =  "git clone --depth=1 git://github.com/mruby/mruby.git"
  if MRUBY_VERSION != 'master'
    cmd << " && cd mruby"
    cmd << " && git fetch --tags && git checkout $(git rev-parse #{MRUBY_VERSION})"
  end
  sh cmd
end

desc "install rust"
task :rust do
  sh "curl https://sh.rustup.rs -sSf | sh -s -- -y"
end

file :specinfra do
  cmd = "git clone --depth=1 git://github.com/libspecinfra/specinfra.git"
  cmd << " && cd specinfra"
  cmd << " && PATH=$PATH:~/.cargo/bin cargo build"
  cmd << " && sudo cp target/debug/libspecinfra.so /usr/lib"
  sh cmd
end

desc "compile binary"
task :compile => :mruby do
  sh "cd mruby && MRUBY_CONFIG=#{MRUBY_CONFIG} rake all"
end

desc "test"
task :test => :mruby do
  sh "cd mruby && MRUBY_CONFIG=#{MRUBY_CONFIG} rake all test"
end

desc "cleanup"
task :clean do
  exit 0 unless File.directory?('mruby')
  sh "cd mruby && rake deep_clean"
end

task :default => :compile
