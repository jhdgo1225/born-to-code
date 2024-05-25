#include "PmergeMe.hpp"
#include <ctime>

PmergeMe::PmergeMe(int argc, char **argv)
{
    for (int idx = 1; idx < argc; idx++)
    {
        std::pair<int, int> tmp(atoi(argv[idx]), idx - 1);
        vc.push_back(tmp);
        li.push_back(tmp);
    }
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
    vc = rhs.vc;
    li = rhs.li;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    vc.clear();
    li.clear();
    vc = rhs.vc;
    li = rhs.li;
    return (*this);
}

int lowerBoundWithVector(std::vector<int>& vc, int key) {
	int low = 0;
	int high = vc.size();
	while(low < high) {
		int mid = (low + high) / 2;
		if (key <= vc[mid])
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}

void    printElements(std::vector<std::pair<int, int> >& vc)
{
    for (std::vector<std::pair<int, int> >::iterator iter = vc.begin(); iter != vc.end(); iter++)
        std::cout << iter->first << ' ';
    std::cout << '\n';
}

void    mergeInsertionVector(std::vector<std::pair<int, int> >& vc)
{
    int vcSize = vc.size();
    if (vcSize <= 1)
        return ;
    std::vector<std::pair<int, int> > mainChain;
    std::vector<std::pair<int, int> > pendingElements;
    std::vector<std::pair<int, int> >::iterator vcIter = vc.begin();
    for (int idx=0; idx < (vcSize >> 1); idx++)
    {
        std::pair<int, int> mainChainItem = *vcIter++;
        std::pair<int, int> pendingElementsItem = *vcIter++;
        if (mainChainItem.first < pendingElementsItem.first)
        {
            std::pair<int, int> tmp = mainChainItem;
            mainChainItem = pendingElementsItem;
            pendingElementsItem = tmp;
        }
        mainChain.push_back(mainChainItem);
        pendingElements.push_back(pendingElementsItem);
    }
    mergeInsertionVector(mainChain);
    for (int idx = 0; idx < (vcSize >> 1); idx++)
        pendingElements.push_back(pendingElements[mainChain[idx].second]);
    pendingElements.erase(pendingElements.begin(), pendingElements.begin() + (vcSize >> 1));
    if (vcSize % 2)
        pendingElements.push_back(*vcIter);
    
    vc = mainChain;
}

void PmergeMe::mergeInsertionSort()
{
    std::cout << "Before: ";
    printElements(vc);
    // time 변수 추가 후 'Vector' Merge-Insertion Sort 시간 측정 시작
    clock_t startVector = clock();
    // 'Vector' Merge-Insertion Sort 수행
    mergeInsertionVector(vc);
    // 'Vector' Merge-Insertion Sort 시간 측정 종료 후 소요시간 저장
    clock_t endVector = clock();
    double  diffTimeVector = difftime(endVector, startVector) * 1000;
    // =========================================================
    // 'List' Merge-Insertion Sort 시간 측정 시작
    clock_t startList = clock();
    // 'List' Merge-Insertion Sort 수행
    // mergeInsertionList(li);
    // 'List' Merge-Insertion Sort 시간 측정 종료 후 소요시간 저장
    clock_t endList = clock();
    double  diffTimeList = difftime(endList, startList) * 1000;
    std::cout << "After: ";
    printElements(vc);
    std::cout << "Time to process a range of " << vc.size() << " elements with std::vector : " << diffTimeVector << " us" << '\n';
    std::cout << "Time to process a range of " << li.size() << " elements with std::list : " << diffTimeList << " us" << '\n';
}
