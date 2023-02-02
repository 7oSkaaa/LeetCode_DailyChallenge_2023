// Author: Ahmed Hossam

class Solution {
public:

    // return invalid if it's invalid seperation
    string get_ip(vector < int >& part, string& s){
        int n = s.size();
        
        // check if the summation of 4 parts equal to size of the string
        if(n != accumulate(part.begin(), part.end(), 0)) return "invalid";

        // store the ip address will returned and the integer parts
        vector < int > ip(4);
        string ip_address;
        
        
        for(int i = 0, sz = 0; i < 4; sz += part[i], i++){
            // current part after change it to string
            ip[i] = stoi(s.substr(sz, part[i]));

            // check if it in the range between [0, 255]
            if(ip[i] < 0 || ip[i] > 255)
                return "invalid";

            // add this part to the address and if not the last part let's add . to it
            ip_address += to_string(ip[i]) + (i == 3 ? "" : ".");
        }

        // check if there is a part with leading zeros
        return (ip_address.size() - 3 == s.size() ? ip_address : "invalid");
    }

    vector<string> restoreIpAddresses(string& s) {
        // vector to store valid ip addresses
        vector < string > ip_addresses;

        // make 4 nested loop to make 4 parts with these lenghts
        for(int p1 = 1; p1 <= 3; p1++)
            for(int p2 = 1; p2 <= 3; p2++)
                for(int p3 = 1; p3 <= 3; p3++)
                    for(int p4 = 1; p4 <= 3; p4++){

                        // vector to store the size of each part
                        vector < int > part = {p1, p2, p3, p4};

                        // check if it valid seperation
                        string ret = get_ip(part, s);

                        // if it valid so let's add it
                        if(ret != "invalid")
                            ip_addresses.push_back(ret);
                    }

        // valid ip addresses
        return ip_addresses;
    }
};
