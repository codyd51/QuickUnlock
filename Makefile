GO_EASY_ON_ME=1
ARCHS = armv7 arm64
TARGET = iphone:clang:latest:latest
THEOS_BUILD_DIR = Packages

include theos/makefiles/common.mk

TWEAK_NAME = QuickUnlock
QuickUnlock_FILES = Tweak.xm
QuickUnlock_FRAMEWORKS = UIKit
QuickUnlock_FRAMEWORKS += CoreGraphics
QuickUnlock_FRAMEWORKS += QuartzCore
QuickUnlock_CFLAGS = -fobjc-arc

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 SpringBoard"
