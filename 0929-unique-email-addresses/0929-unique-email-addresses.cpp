class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        for(auto& email:emails){
        
            auto at_location = find(email.begin(),email.end(),'@'); //check validity
            auto end_after_removing_dots = remove(email.begin(),at_location,'.');   //remove extra
			auto plus_location = find(email.begin(),end_after_removing_dots,'+');   //to remove after + find position
        
            email.erase(plus_location,at_location);
        
        }
        return unordered_set(emails.begin(),emails.end()).size();
    }
};