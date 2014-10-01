# DLog

Debugging and Logging with light speed. Don't write type casts in the debugger again. Just simply write `[DLog CGRect:myRect]` in the debugger, or `DLogCGRect(myRect)` in code, everything is autocompleted!

## Purpose

DLog is just a collection of **class** methods that execute C functions or objc methods. During debug sessions it becomes tedious quickly to write `po (NSString*)NSStringFromCGRect(myRect)`. DLog solves this with a collection of **class** methods. I find myself reaching for this file commonly early in the life cycle of a project. It's delightful typing just a couple keys like 'D' TAB 'O' TAB and 'DLogObject' is autocompleted.

## Setup

    #import <DLog/DLog.h>

TIP: Import in your Prefix.pch to include project-wide.

## Usage in code

    DLogObject(myObject);
    DLogNSObject(myObject); // => DL:myObject;hello, world!;
    
    
    DLogFunctionLine(); // => DL:-[TableViewController viewDidLoad]:15
    
    
    DLogBOOL(myValue); // => DL:myValue;YES;
    
    
    DLogSEL(mySelector); // => DL:mySelector;buttonAction:;
    
    
    DLogCGFloat(myCGFloat);
    DLogunichar(myUnichar);
    DLogUIColor(myColor);
    
    
    DLogMainThread() // => DL:-[TableViewController viewDidLoad];15:MainThread=YES;
    
    
    DLogTimeStart(1);
    DLogTimeEnd(1); // => DL:1;4123;
    ...
    
    
## Usage in debugger

    po [DLog Selector:mySelector] // => viewDidAppear:
    
    po [DLog CGRect:myRect] // => {0, 0, 320, 80}
    
    po [DLog UIGestureRecognizerState:myState] // => UIGestureRecognizerStateBegan
    
    po [DLog cTypeEncoding:myObject] // => id
    po [DLog cTypeEncoding:myInt] // => int
    po [DLog cTypeEncoding:&myInt] // => int*
    po [DLog cTypeEncoding:myCGFloat] // => (32bit) float, (64bit) double
    ...


## Easy

Saving UIImage from debugger to file

    po [DLog base64EncodedStringWithUIImage:myImage];
    
**TIP:** Copy paste the string to a base64 image decoder online.
    
Recursive print UIView hierarchy

    po [DLog UIView:myView];
    
Print most UIKit values

    po [DLog UIOffset:myOffset];
    po [DLog UIEdgeInsets:myInsets];

## Advanced Usage

DLog gives you fast access to the static typing system and objc runtime. 

    DLogBytes(myPointer);
    DLogByteOrder(); // => LittleEndian
    DLogTypeEncoding(myValue); // => unsigned long long
    
    // print exception reason
    DLogException(myException);
    
    // print stack trace
    DLogException([[NSException new] raise]);

Do you see the pattern? DLog allows multiple ways of doing things, there is no right way, just the fastest.

    DLogfloat(myFloat);
    
    DLogid(myObject);
    DLogObject(myObject);
    DLogNSObject(myObject);
    
    DLogNSInteger(myNSInteger);
    
    DLogNSUInteger(myNSUInteger);
    
    DLoglong(myLong);
    DLogunsignedlong(myUnsignedLong);
    DLoglonglong(myLongLong); 
    ...
    
Also handy methods are included even if they are fast to write by hand because it's easier to set `#define DEBUG 0` and remove all logging statements at once. Assert methods are prefixed with `DAssert`. 

    DAssertMainThread();
    DAssertNil();
    DAssertNonNil();
    
    
## Private Methods

`DLogUIView` and `[DLog performLowMemoryWarning]` call private methods at runtime. There are no compiler errors because the selector is dynamically evaluated and the function is manually looked up (see source). Due to this reason, it is not recommended to include DLog in any public releases on the App Store.

## Configuration

DLog is not meant to be included in production, it's automatically removed and replaced with `do{}while(0)` statements in release which get optimized out. If you would like to include DLog in production, simply set `#define DLOG 1`.

    #define DEBUG 0
    #define DLOG 1
    
    DLogObject(myDate); // => NSLog(@"%s:%s:%@", 'DL', 'myDate', myDate);

DLog Logging methods include a prefix (by default 'DL') but this can be configured.

    #define DLOG_PREFIX MYPREFIX
    
## Contribution Guide

- If you found a bug, open an issue.
- If you have a feature request, open an issue.
- If you want to contribute, follow steps below to submit a pull request.

1. Fork
2. **Create a new branch with username-myfeature** 
- Ex: gauravk92-adding-more-encodings-to-cTypeEncoding-method
- Ex: gauravk92-fix-bug-on-osx-nsrange-method
- Ex: gauravk92-add-JSValue-to-json-log-method
3. Commit and submit pull request

## Contact

Follow Gaurav Khanna on Twitter ([@gauravk92](https://twitter.com/gauravk92))

## License

DLog is available under the MIT license. See the LICENSE file for more info.