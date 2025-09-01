void processApplications(const vector<Item>& itemList) {
    int password;
    cout << "관리자 password를 입력하세요 : ";
    cin >> password;
    if (password == 4976) {
        cout << "\n[관리자 승인]\n";
        vector<Request*> pendingRequests;
        for (Request& req : requestList) {
            if (!req.approved) {
                pendingRequests.push_back(&req);
            } 
        }
        if (pendingRequests.empty()) {
            cout << "승인 대기 중인 신청이 없습니다.\n";
            return; 
        }
        cout << "승인 대기 중인 신청 목록:\n";
        //이전과 동일
        int requestIndex;
        cout << "승인할 신청 번호 (0부터 시작, -1: 모두 승인, -2: 취소) 를 입력하세요: ";
        cin >> requestIndex;
        if (cin.fail()) {
            cerr << "오류: 잘못된 입력입니다. 숫자를 입력해주세요.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return; 
        }
        if (requestIndex == -2) {
            cout << "관리자 승인을 취소합니다.\n";
            return; 
        }
        if (requestIndex == -1) {
            for (Request* req : pendingRequests) {
                req->approved = true;
                Item approvedItemInfo;
                for (const auto& item : itemList) {
                    if (item.number == req->itemNumber) {
                        approvedItemInfo = item;
                        break;
                    } 
                }
                approvedItemList.push_back({approvedItemInfo, chrono::system_clock::now()});
            }
            cout << "모든 신청이 승인되었습니다.\n";
        }  else if (requestIndex >= 0 && (size_t)requestIndex < pendingRequests.size()) {
            pendingRequests[requestIndex]->approved = true;
            Item approvedItemInfo;
            for(const auto& item : itemList){
              if(item.number == pendingRequests[requestIndex]->itemNumber){
                approvedItemInfo = item;
                break;
              } }
            approvedItemList.push_back({approvedItemInfo, chrono::system_clock::now()});
            cout << "신청이 승인되었습니다.\n";
        }else {
            cout << "오류: 잘못된 신청 번호입니다.\n";
        }
    } else { 
        cout << "입력 오류 : 관리자 업무 수행이 불가합니다. \n";
 }
}
