Pod::Spec.new do |s|
  s.name         = 'DLog'
  s.version      = '1.0.1'
  s.summary      = 'An insanely useful debug logging class. Ex: DLogUIGestureRecognizerState(myState);'
  s.homepage     = 'https://github.com/gauravk92/DLog'
  s.license      = { :type => 'MIT' }
  s.author       = { 'Gaurav Khanna' => 'gauravk92@gmail.com' }
  s.social_media_url = 'https://twitter.com/gauravk92'

  s.ios.deployment_target = '5.0'
  s.osx.deployment_target = '10.7'
  
  s.source       = { :git => 'https://github.com/gauravk92/DLog.git', :tag => s.version.to_s }
  s.source_files = 'DLog/*.{h,m}'
  s.preserve_paths = 'README*'
  s.ios.framework = 'UIKit', 'GLKit'
  s.osx.framework = 'AppKit', 'GLKit'
  s.requires_arc = true
end
