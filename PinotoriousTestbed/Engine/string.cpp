#include "pch.h"
#include "string.h"


void StringBase::Set(const char*data, int dataLength)
{
	char *internalData = GetDataInternalMutable();
	int internalDataSize = GetStringDataSizeInternal();

	for (int index = 0; index < dataLength; index++)
	{
		if (index > internalDataSize)
		{
			// TODO: Report Error
			break;
		}
		internalData[index] = data[index];
	}
}

const char* StringBase::GetData() const
{
	return GetDataInternal();
}

StringBase::StringBase(const char *data)
{
	Set(data, strlen(data));
}
