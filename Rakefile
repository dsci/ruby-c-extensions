require 'rake/extensiontask'
require 'rake/testtask'

Rake::TestTask.new(:test => [:clean,:compile]) do |t|
  t.libs << "test"
  t.test_files = FileList['test/**/*.rb']
end

Rake::ExtensionTask.new('ary')
