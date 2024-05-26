#include "PmergeMe.hpp"
#include <ctime>

int cnt;
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

void    printElements(std::vector<std::pair<int, int> >& vc)
{
    for (std::vector<std::pair<int, int> >::iterator iter = vc.begin(); iter != vc.end(); iter++)
        std::cout << iter->first << ' ';
    std::cout << '\n';
}

std::vector<std::pair<int, int> >::iterator lowerBoundVector(std::vector<std::pair<int, int> >& vc, std::vector<std::pair<int, int> >::iterator s, std::vector<std::pair<int, int> >::iterator e, std::pair<int, int> key)
{
    std::vector<std::pair<int, int> >::iterator retIter = vc.begin();
    int low = 0;
    int high = e - s;
    int mid;
    while (low < high)
    {
        cnt++;
        mid = (low + high) / 2;
        if (key.first <= vc[mid].first)
            high = mid;
        else
            low = mid + 1;
    }
    for (int idx = 0; idx < low; idx++)
        retIter++;
    return (retIter);
}

void insertInVector(std::vector<std::pair<int, int> >& mainChain, std::vector<std::pair<int, int> >& pendingElements, int vcSize)
{
    std::vector<std::pair<int, int> > newMainChain;
    std::vector<std::pair<int, int> > tmp;
    std::vector<std::pair<int, int> >::iterator endIter;
    std::vector<std::pair<int, int> >::iterator InsertionIter;
    int n1 = 0, n2 = 1, end = 0, start = 1;
    int mainChainSize = mainChain.size();
    int pendingElementsSize = pendingElements.size();
    newMainChain.push_back(pendingElements[0]);
    newMainChain.push_back(mainChain[0]);
    while (vcSize != static_cast<int>(newMainChain.size()))
    {
        n1 = n2;
        n2 = start;
        end = start;
        start = n1 * 2 + n2;
        if (start > pendingElementsSize)
            start = pendingElementsSize;
        for (int idx2 = end; (idx2 < start && idx2 < mainChainSize); idx2++)
            newMainChain.push_back(mainChain[idx2]);
        for (int idx2 = start; idx2 > end; idx2--)
        {
            if (newMainChain.back().first <= pendingElements[idx2 - 1].first)
            {
                tmp.push_back(pendingElements[idx2 - 1]);
                continue ;
            }
            endIter = newMainChain.end();
            endIter--;
            InsertionIter = newMainChain.insert(lowerBoundVector(newMainChain, newMainChain.begin(), endIter, pendingElements[idx2 - 1]), pendingElements[idx2 - 1]);
            tmp.push_back(newMainChain.back());
            newMainChain.pop_back();
            if (InsertionIter - newMainChain.begin() + 1 == newMainChain.end() - newMainChain.begin())
            {
                tmp.push_back(newMainChain.back());
                newMainChain.pop_back();
            }
        }
        while (!tmp.empty())
        {
            newMainChain.push_back(tmp.back());
            tmp.pop_back();
        }
    }
    mainChain = newMainChain;
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
        cnt++;
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
    std::vector<std::pair<int, int> > updatedMainChain;
    std::vector<std::pair<int, int> > updatedPendingElements;
    for (std::vector<std::pair<int, int> >::iterator it = mainChain.begin(); it != mainChain.end(); it++)
        updatedMainChain.push_back(std::pair<int, int>(it->first, it - mainChain.begin()));
    mergeInsertionVector(updatedMainChain);
    for (int idx = 0; idx < (vcSize >> 1); idx++)
    {   
        int updatedIdx = updatedMainChain[idx].second;
        updatedPendingElements.push_back(pendingElements[updatedIdx]);
        updatedMainChain[idx].second = mainChain[updatedIdx].second;
    }
    if (vcSize % 2)
        updatedPendingElements.push_back(*vcIter);
    insertInVector(updatedMainChain, updatedPendingElements, vcSize);
    vc = updatedMainChain;
}

void PmergeMe::mergeInsertionSort()
{
    std::cout << "Before: ";
    printElements(vc);
    clock_t startVector = clock();
    mergeInsertionVector(vc);
    clock_t endVector = clock();
    double  diffTimeVector = endVector - startVector;
    // =========================================================
    // 'List' Merge-Insertion Sort 시간 측정 시작
    clock_t startList = clock();
    // 'List' Merge-Insertion Sort 수행
    // mergeInsertionList(li);
    // 'List' Merge-Insertion Sort 시간 측정 종료 후 소요시간 저장
    clock_t endList = clock();
    double  diffTimeList = endList - startList;
    std::cout << "After: ";
    printElements(vc);
    std::cout << "Time to process a range of " << vc.size() << " elements with std::vector : " << diffTimeVector / CLOCKS_PER_SEC << " s" << '\n';
    std::cout << "Time to process a range of " << li.size() << " elements with std::list : " << diffTimeList << " s" << '\n';
    std::cout << cnt << '\n';
}
