//
// Created by yaros on 29.11.2022.
//

struct ShannonFano{
    string code;
    string encode(string line){
        string result = "";
        int size = line.size();
        int count = 0;
        int pos = 0;
        while (count < size){
            int length = 0;
            int sum = 0;
            int i = 0;
            while (sum < size / 2){
                sum += line[pos + i];
                i++;
            }
            length = i;
            for (int j = 0; j < length; j++){
                result += '0';
            }
            for (int j = 0; j < size - length; j++){
                result += '1';
            }
            pos += length;
            count += length;
        }
        code = result;
        return result;
    }
};