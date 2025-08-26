#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

/*
  Problem:
  --------
  Given a set of airline tickets as (source -> destination) pairs in an unordered_map,
  reconstruct and print the complete travel path in order.

  Key Idea:
  ---------
  In a valid single-chain itinerary, exactly one city appears only as a source and never
  as a destination — that city is the unique starting point. Every other city is both a
  destination (arrived from somewhere) and possibly a source (to go somewhere next).

  What this code does:
  --------------------
  1) Collect all destination cities into an unordered_set 's'.
     - Any city that appears in 's' is someone's destination.
  2) Find the starting city 'start' by scanning all (source -> destination) pairs and
     picking the source that is NOT present in 's'. That source never appears as a
     destination, so it must be the beginning of the route.
  3) Starting from 'start', repeatedly follow tickets[start] to hop from city to city
     and print each step:
        start -> tickets[start] -> tickets[tickets[start]] -> ...
     The loop stops when there is no next destination. This is detected because using
     operator[] on an unordered_map for a missing key yields an empty string (""), which
     the code checks to terminate the traversal.

  Assumptions & Notes:
  --------------------
  - Assumes the tickets form a single valid chain (no forks/branches and no cycles).
  - If there is a cycle, the traversal could loop indefinitely; this approach expects a
    proper end city that does not map to another destination.
  - Printing order is deterministic for the path; set/map iteration order itself is not.
  - The code prints the sequence as: "start -> <city1> -> <city2> -> ... -> destintion".

  Complexity:
  -----------
  Let n be the number of tickets.
  - Building the destination set: O(n) average time.
  - Finding the start city: O(n).
  - Following the path and printing: O(n).
  - Extra space: O(n) for the destination set.
*/

void itenary(unordered_map<string, string> tickets){
    unordered_set<string> s;
        for(pair<string, string>  itr : tickets){
            s.insert(itr.second);
        }
    
        string start = " ";
        for(auto itr : tickets){
            if(s.find(itr.first) == s.end()){
                start = itr.first;
            }
        }

        cout << "start -> " << start << " -> ";
        while(tickets[start] != ""){
            start = tickets[start];
            cout << start << " -> ";
        }
        cout << "destintion" << endl;
}

int main(){
    unordered_map<string, string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    itenary(tickets);
    return 0;
}
