#include <Tests/write_file.test.h>

    static test_log_prefixes message_anatomy;

    message_anatomy["TEST_FILE"]["NAME"] = "WRITE_FILE.CPP";
    message_anatomy["TEST_TYPE"]["RET_T"] = "RETURN TYPE";
    message_anatomy["TEST_TYPE"]["RET_V"] = "RETURN VALUE";
    message_anatomy["TEST_TYPE"]["INT_V"] = "INT VALUE";
    message_anatomy["TEST_STATUS"]["p"] = "PASSED!";
    message_anatomy["TEST_STATUS"]["F"] = "FAILED!";
    message_anatomy["TEST_FAIL_SUFFIX"]["EXPECTED"] = "Expected VALUE";
    message_anatomy["TEST_FAIL_SUFFIX"]["ACTUAL"] = "ACTUAL VALUE";
    message_anatomy["SEPARATOR"]["SEP_ONE"] = " :: ";
    message_anatomy["SEPARATOR"]["SEP_TWO"] = " ";

void checkReturnType() {

    
    string test_log = "";

    auto return_value = write_file("", "");
    
    if(typeid(return_value) != typeid(int)) {

        test_log.append(message_anatomy["TEST_FILE"]["NAME"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append(message_anatomy["TEST_TYPE"]["RET_T"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append("TEST 1");
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append(message_anatomy["TEST_STATUS"]["F"]);
        test_log.append("\n\t");
        test_log.append(message_anatomy["TEST_FAIL_SUFFIX"]["EXPECTED"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_TWO"]);
        test_log.append("int");
        test_log.append(message_anatomy["SEPARATOR"]["SEP_TWO"]);
        test_log.append(message_anatomy["TEST_FAIL_SUFFIX"]["ACTUAL"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_TWO"]);
        test_log.append(typeid(return_value).name());
        test_log.append("\n");
        
        cout << test_log << endl;

        test_log = "";

    } else {

        test_log.append(message_anatomy["TEST_FILE"]["NAME"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append(message_anatomy["TEST_TYPE"]["RET_T"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append("TEST 1");
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append(message_anatomy["TEST_STATUS"]["P"]);
        test_log.append("\n");
        
        cout << test_log << endl;

        test_log = "";

    }

    return_value = write_file("testit.new", "");

    if(typeid(return_value) != typeid(int)) {

        test_log.append(message_anatomy["TEST_FILE"]["NAME"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append(message_anatomy["TEST_TYPE"]["RET_T"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append("TEST 1");
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append(message_anatomy["TEST_STATUS"]["F"]);
        test_log.append("\n\t");
        test_log.append(message_anatomy["TEST_FAIL_SUFFIX"]["EXPECTED"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_TWO"]);
        test_log.append("int");
        test_log.append(message_anatomy["SEPARATOR"]["SEP_TWO"]);
        test_log.append(message_anatomy["TEST_FAIL_SUFFIX"]["ACTUAL"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_TWO"]);
        test_log.append(typeid(return_value).name());
        test_log.append("\n");
        
        cout << test_log << endl;

        test_log = "";

    } else {

        test_log.append(message_anatomy["TEST_FILE"]["NAME"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append(message_anatomy["TEST_TYPE"]["RET_T"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append("TEST 1");
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append(message_anatomy["TEST_STATUS"]["P"]);
        test_log.append("\n");
        
        cout << test_log << endl;

        test_log = "";

    }

    return_value = write_file("testit.new", "this is working!!");

    if(typeid(return_value) != typeid(int)) {

        test_log.append(message_anatomy["TEST_FILE"]["NAME"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append(message_anatomy["TEST_TYPE"]["RET_T"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append("TEST 1");
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append(message_anatomy["TEST_STATUS"]["F"]);
        test_log.append("\n\t");
        test_log.append(message_anatomy["TEST_FAIL_SUFFIX"]["EXPECTED"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_TWO"]);
        test_log.append("int");
        test_log.append(message_anatomy["SEPARATOR"]["SEP_TWO"]);
        test_log.append(message_anatomy["TEST_FAIL_SUFFIX"]["ACTUAL"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_TWO"]);
        test_log.append(typeid(return_value).name());
        test_log.append("\n");
        
        cout << test_log << endl;

        test_log = "";

    } else {

        test_log.append(message_anatomy["TEST_FILE"]["NAME"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append(message_anatomy["TEST_TYPE"]["RET_T"]);
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append("TEST 1");
        test_log.append(message_anatomy["SEPARATOR"]["SEP_ONE"]);
        test_log.append(message_anatomy["TEST_STATUS"]["P"]);
        test_log.append("\n");
        
        cout << test_log << endl;

        test_log = "";

    }
}


void checkReturnValue() {

    auto return_value = write_file("", "");
    
    if(return_value != 1) {

        cout << "Expected value 1 (int) :: Actual: " << return_value << endl;

    } else {

        cout << "Write_FILE :: Test [1] Passed!" << endl;

    }

}