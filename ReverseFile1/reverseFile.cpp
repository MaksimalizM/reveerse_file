#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        return 1;
    }

    const char* inputFileName = argv[1];
    const char* outputFileName = argv[2];

    std::ifstream inputFile(inputFileName, std::ios::binary);
    if (!inputFile) {
        std::cerr << "dont opened input file" << std::endl;
        return 1;
    }

    std::ofstream outputFile(outputFileName, std::ios::binary);
    if (!outputFile) {
        std::cerr << "dont created or opened output file" << std::endl;
        return 1;
    }

    std::vector<char> buffer(std::istreambuf_iterator<char>(inputFile), {});
    int k = buffer.size();
    int r = k;
    k = k / 16 * 8;
    int j;
    for (int i = 0; i < k; i++) {
        if (i % 8 == 0 && i > 0)
            r = r - 16;
        char& e = buffer.at(i);
        j = e;
        buffer.at(i) = buffer.at(r - 8 + i);
        buffer.at(r - 8 + i) = j;
    }

    outputFile.write(buffer.data(), buffer.size());
    std::cout << "successful" << std::endl;
    return 0;
}