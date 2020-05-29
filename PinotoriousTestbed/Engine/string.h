#pragma once
#ifndef STRING_H
#define STRING_H

class StringBase
{
public:
	void Set(const char*data, int dataLength);
	const char* GetData() const;
	int32 GetLength() { return strlen(GetData()); }
	bool IsEmpty() { return GetData()[0] == 0; }

	//operator = (const char* data) { Set(data, strlen(data)); }

	StringBase(const char *data);
private:
	virtual const char *GetDataInternal() const = 0;
	virtual char *GetDataInternalMutable()= 0;
	virtual int GetStringDataSizeInternal() = 0;

};

template <int length>
class String : public StringBase
{
public:
	String(const char *data) : StringBase(data) { Set(data, strlen(data)); }

private:
	virtual char *GetDataInternalMutable() { return data; }
	virtual const char*GetDataInternal() const { return data; }
	virtual int GetStringDataSizeInternal() { return length; }

	char data[length];

};

#endif //#ifndef STRING_H