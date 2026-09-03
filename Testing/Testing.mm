//
//  Testing.m
//  Testing
//
//  Created by Rosairy Paniagua Garcia on 9/2/26.
//

#import <XCTest/XCTest.h>
#import "problemSolving.hpp"

@interface Testing : XCTestCase

@end

@implementation Testing

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testExample {
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
    // XCTest Documentation
    // https://developer.apple.com/documentation/xctest
    
    std::vector <std::string> d = {"L105"};
    
    int result = 5;
    int count = 0;
    
    Password::Break(d, 0, result, count);
    
    XCTAssertEqual(result, 0);
    XCTAssertEqual(count, 2);
  


//        XCTAssertEqual(Mathematics().add(1, 1), 2);
    
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
