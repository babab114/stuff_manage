void adminApprove() { // 관리자 승인 함수
    cout << "\n[관리자 승인]\n";
    if (requestList.empty()) {
        cout << "승인 대기 중인 신청이 없습니다.\n";
        return;
    }

    cout << "승인 대기 중인 신청 목록:\n";
    printRequestList(); // 신청 리스트 출력 함수 재사용

    int requestIndex;
    cout << "승인할 신청 번호 (0부터 시작, -1: 취소)를 입력하세요: ";
    cin >> requestIndex;

    if (cin.fail()) {
        cerr << "오류: 잘못된 입력입니다. 숫자를 입력해주세요.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (requestIndex == -1) {
        cout << "관리자 승인을 취소합니다.\n";
        return;
    }

    if (requestIndex >= 0 && requestIndex < requestList.size()) {
        requestList[requestIndex].approved = true;
        cout << "신청이 승인되었습니다.\n";
    } else {
        cout << "오류: 잘못된 신청 번호입니다.\n";
    }
}
