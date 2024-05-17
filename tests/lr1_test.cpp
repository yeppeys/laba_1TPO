#include "lr1.h"
#include <gtest/gtest.h>
#include <vector>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include <any>

using namespace std;
using namespace testing;
using json = nlohmann::json;

string ReadTestDataFromJsonFile(const string& filename) {
    string testData;
    ifstream file(filename);
    string line;
    while (getline(file, line)) testData += line;
    return testData;
}

class FileBasedTest : public Test {
protected:
    json parsed_json;

    void SetUp() override {
        parsed_json = json::parse(ReadTestDataFromJsonFile("../tests/test_data.json"));
    }

    void TearDown() override {
        parsed_json.clear();
    }

    void TEST_F_Body(const string& testName){
        auto data = parsed_json[testName];
        vector<string> input;
        for (const auto &item: data["input"].items())
            if (item.value().is_string()) input.push_back(item.value());
            else input.push_back(to_string(item.value()));

        auto response = Solution(input);

        int sum = data["sum"];
        vector<int> result = data["result"];
        map<string, vector<string>> errors;
        for (const auto &i: data["errors"].items()) {
            errors[i.key()];
            for (const auto &j: i.value())
                if (j.is_string()) errors[i.key()].emplace_back(j);
                else errors[i.key()].emplace_back(to_string(j));
        }

        EXPECT_EQ(response.sum, sum);
        EXPECT_EQ(response.result, result);
        EXPECT_EQ(response.errors, errors);
    }
};

TEST_F(FileBasedTest, test1) { TEST_F_Body("test1");}
TEST_F(FileBasedTest, test2) { TEST_F_Body("test2");}
TEST_F(FileBasedTest, test3) { TEST_F_Body("test3");}
TEST_F(FileBasedTest, test4) { TEST_F_Body("test4");}
TEST_F(FileBasedTest, test5) { TEST_F_Body("test5");}
TEST_F(FileBasedTest, test6) { TEST_F_Body("test6");}
TEST_F(FileBasedTest, test7) { TEST_F_Body("test7");}
TEST_F(FileBasedTest, test8) { TEST_F_Body("test8");}
TEST_F(FileBasedTest, test9) { TEST_F_Body("test9");}
TEST_F(FileBasedTest, test10) { TEST_F_Body("test10");}
TEST_F(FileBasedTest, test11) { TEST_F_Body("test11");}
TEST_F(FileBasedTest, test12) { TEST_F_Body("test12");}
TEST_F(FileBasedTest, test13) { TEST_F_Body("test13");}
TEST_F(FileBasedTest, test14) { TEST_F_Body("test14");}
TEST_F(FileBasedTest, test15) { TEST_F_Body("test15");}
TEST_F(FileBasedTest, test16) { TEST_F_Body("test16");}
TEST_F(FileBasedTest, test17) { TEST_F_Body("test17");}
TEST_F(FileBasedTest, test18) { TEST_F_Body("test18");}
TEST_F(FileBasedTest, test19) { TEST_F_Body("test19");}
TEST_F(FileBasedTest, test20) { TEST_F_Body("test20");}

