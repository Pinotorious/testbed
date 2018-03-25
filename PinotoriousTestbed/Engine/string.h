#pragma once
#ifndef STRING_H
#define STRING_H

class StringBase
{
public:
	void Set(const char*data, int dataLength);
	const char* GetData() const;
private:
	virtual const char *GetDataInternal() const = 0;
	virtual char *GetDataInternalMutable()= 0;
	virtual int GetStringDataSizeInternal() = 0;

};

template <int length>
class String : public StringBase
{
public:


private:
	virtual char *GetDataInternalMutable() { return data; }
	virtual const char*GetDataInternal() const { return data; }
	virtual int GetStringDataSizeInternal() { return length; }

	char data[length];

};

#endif //#ifndef STRING_H