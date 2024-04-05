Pod::Spec.new do |spec|
  spec.name = 'QuantActionsExtraFrameworks'
  spec.version = '4.22.0'
  spec.summary = 'QuantActions Extra Frameworks'
  spec.description = 'Extra frameworks of QuantActionsSDK'
 
  spec.homepage = 'https://github.com/QuantActions/quantactions-extra-frameworks'
  spec.source = { :git => 'https://github.com/QuantActions/quantactions-extra-frameworks.git', :tag => spec.version }
  spec.documentation_url = 'https://github.com/QuantActions/quantactions-extra-frameworks'
  spec.authors = { 'QuantActions' => 'development@quantactions.com' }
  spec.license = { :type => "CC-NC-ND", :file => "LICENSE" }

  spec.vendored_frameworks = 'frameworks/FleksyAppsCore.xcframework', 'frameworks/FleksyEngine.xcframework', 'frameworks/FleksyKeyboardSDK.xcframework', 'frameworks/iOSCoreServices.xcframework'

  spec.ios.deployment_target = '16.0'
  spec.swift_versions = ['5']

end