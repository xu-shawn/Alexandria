
#include "Board.h"
#include "PieceData.h"
#include <map>
#include "eval.h"
#include <string>

// convert ASCII character pieces to encoded constants

std::map<char, int> char_pieces = {
        {'P',WP},
        {'N',WN},
        {'B',WB},
        {'R',WR},
        {'Q',WQ},
        {'K',WK},
        {'p',BP},
        {'n',BN},
        {'b',BB},
        {'r',BR},
        {'q',BQ},
        {'k',BK}

};

std::map<int, char> promoted_pieces = { 
        {WQ,'q'},
        {WR,'r'},
        {WB,'b'},
        {WN,'n'},
        {BQ,'q'},
        {BR,'r'},
        {BB,'b'},
        {BN,'n'} };
      




// MVV LVA [attacker][victim]
const int mvv_lva[12][12] = {
    105, 205, 305, 405, 505, 605,  105, 205, 305, 405, 505, 605,
    104, 204, 304, 404, 504, 604,  104, 204, 304, 404, 504, 604,
    103, 203, 303, 403, 503, 603,  103, 203, 303, 403, 503, 603,
    102, 202, 302, 402, 502, 602,  102, 202, 302, 402, 502, 602,
    101, 201, 301, 401, 501, 601,  101, 201, 301, 401, 501, 601,
    100, 200, 300, 400, 500, 600,  100, 200, 300, 400, 500, 600,

    105, 205, 305, 405, 505, 605,  105, 205, 305, 405, 505, 605,
    104, 204, 304, 404, 504, 604,  104, 204, 304, 404, 504, 604,
    103, 203, 303, 403, 503, 603,  103, 203, 303, 403, 503, 603,
    102, 202, 302, 402, 502, 602,  102, 202, 302, 402, 502, 602,
    101, 201, 301, 401, 501, 601,  101, 201, 301, 401, 501, 601,
    100, 200, 300, 400, 500, 600,  100, 200, 300, 400, 500, 600
};