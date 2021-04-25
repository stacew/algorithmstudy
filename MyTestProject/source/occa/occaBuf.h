#pragma once

#ifdef _DEBUG
static int testUseHeapCount = 0;
static int testUseStackCount = 0;
#endif

enum class eOcca {
    malloc, malloc_initZero,
    //todo: calloc(initCount), realloc
};

template< typename type, const size_t SET_STACK_TYPE_COUNT >
class occaBuf {

private:
	type m_stackMemory[SET_STACK_TYPE_COUNT];
	type* m_pHeapMemory;
	eOcca m_eAllocType;
	bool m_bUseStack;
	bool m_bAllocaFail;

public:
	inline type* GetBuffer() { return m_bUseStack ? m_stackMemory : m_pHeapMemory; }
	bool isAllocFail() { return m_bAllocaFail; }

protected:
	void init_occaBuf(size_t _needAllocSize, eOcca _eAllocType) {
		m_bAllocaFail = false;
		m_pHeapMemory = nullptr;
		m_eAllocType = _eAllocType;

		m_bUseStack = true;
		if (_needAllocSize > SET_STACK_TYPE_COUNT * sizeof(type)) {

			m_pHeapMemory = (type*)malloc(_needAllocSize); //todo : calloc, realloc

			if (m_pHeapMemory == nullptr) {
				assert(m_pHeapMemory != nullptr);
				m_bAllocaFail = true;
				return;
			}

			m_bUseStack = false;
		}

		if (m_eAllocType == eOcca::malloc_initZero)
			memset(GetBuffer(), 0, _needAllocSize);

#ifdef _DEBUG
		if (m_bUseStack)
			testUseStackCount++;
		else
			testUseHeapCount++;
#endif
	}


	~occaBuf() {

		if (m_bUseStack) {
			assert(m_pHeapMemory == nullptr);//_needAllocSize 보다 더 많이 기록되었을 경우, m_pHeapMemory를 오염시킨다.
			return;
		}

		free(m_pHeapMemory);
	}

    inline static size_t countToSize(size_t _typeCount) {
        return sizeof(type) * _typeCount;
    }

};


//64 배수.
template<typename type>
class occaBuf256 : public occaBuf<type, 256> {
    using super = occaBuf<type, 256>;
public:
    occaBuf256(size_t _typeCount, eOcca _eAllocType) { super::init_occaBuf(super::countToSize(_typeCount), _eAllocType); }
    occaBuf256(size_t _typeCount, size_t _addAllocSize, eOcca _eAllocType) { super::init_occaBuf(super::countToSize(_typeCount) + _addAllocSize, _eAllocType); }
};
