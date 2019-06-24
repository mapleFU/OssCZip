#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]

include!(concat!(env!("OUT_DIR"), "/zip.rs"));

use std::ffi::CString;

#[test]
fn test_compress() {
    println!("Hello world");
    let from_s = "/Users/fuasahi/ClionProjects/oss-storage-layer/OssCZip/data/4 (1)的副本.jpg".to_string();
    let to_s = "/Users/fuasahi/ClionProjects/oss-storage-layer/OssCZip/data/4 (1)的副本.jpg.zip".to_string();
    let s = CString::new(from_s).unwrap();
    let to = CString::new(to_s).unwrap();


    unsafe {
        self::oss_compress(s.as_ptr(), to.as_ptr());
    }
}