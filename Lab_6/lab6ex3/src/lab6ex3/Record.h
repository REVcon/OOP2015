#pragma once
class CRecord
{
public:
	CRecord(const std::string &s);
	~CRecord();
	std::shared_ptr<CRecord> GetPrev() const;
	std::shared_ptr<CRecord> GetNext() const;
	std::string GetValue() const;
	void SetPrev(const std::shared_ptr<CRecord> &prev);
	void SetNext(const std::shared_ptr<CRecord> &prev);
private:
	std::string m_value;
	std::shared_ptr<CRecord> m_next, m_prev;
};