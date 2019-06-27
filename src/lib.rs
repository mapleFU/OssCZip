#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

include!(concat!(env!("OUT_DIR"), "/zip.rs"));

use std::ffi::CString;
use std::fs;

#[test]
fn test_compress() {
    let from_s = "data/testimg.png".to_string();
    let to_s = "data/testimg.png.zip".to_string();
    let s = CString::new(from_s).unwrap();
    let to = CString::new(to_s).unwrap();


    unsafe {
        self::oss_compress(s.as_ptr(), to.as_ptr());
    }

}