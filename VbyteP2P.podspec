#
# Be sure to run `pod lib lint VbyteP2P.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'VbyteP2P'
  s.version          = '1.0.2'
  s.summary          = 'P2P engine for videos playback.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
This is a library for ios, it can help your app reduce bandwidth cost rely on its peer-to-peer acceleration. It is maintained by Vbyte.cn. Welcome and Thank you for using it!
                       DESC

  s.homepage         = 'https://github.com/Vbytes/VbyteP2PFramework'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Vbytes' => 'repository@exatech.cn' }
  s.source           = { :git => 'https://github.com/Vbytes/VbyteP2PFramework.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  # s.source_files = 'VbyteP2P/Classes/**/*'
  s.ios.vendored_frameworks = 'VbyteP2P/Frameworks/VbyteP2P.framework'
  s.ios.libraries = "stdc++.6.0.9"
  # s.ios.compiler_flags = '-std=gnu++98', '-stdlib=libstdc++'
end
