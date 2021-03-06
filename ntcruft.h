
#define SystemModuleInformation 0xb
#define SystemBootEnvironmentInformation 0x5a
#define SystemCodeIntegrityInformation 0x67
#define SystemSecureBootPolicyInformation 0x8f
typedef struct {
	HANDLE Section;
	PVOID MappedBase;
	PVOID ImageBase;
	ULONG ImageSize;
	ULONG Flags;
	USHORT LoadOrderIndex;
	USHORT InitOrderIndex;
	USHORT LoadCount;
	USHORT OffsetToFileName;
	UCHAR FullPathName[256];
} RTL_PROCESS_MODULE_INFORMATION;
typedef struct {
	ULONG NumberOfModules;
	RTL_PROCESS_MODULE_INFORMATION Modules[1];
} RTL_PROCESS_MODULES;

typedef struct {
	PVOID QueryRoutine;
	ULONG Flags;
	PCWSTR Name;
	PVOID EntryContext;
	ULONG DefaultType;
	PVOID DefaultData;
	ULONG DefaultLength;
} RTL_QUERY_REGISTRY_TABLE;

NTSTATUS NTAPI NtLoadDriver(PUNICODE_STRING);
NTSTATUS NTAPI NtUnloadDriver(PUNICODE_STRING);
NTSTATUS NTAPI RtlCreateRegistryKey(ULONG,PWSTR);
NTSTATUS NTAPI RtlWriteRegistryValue(ULONG,PCWSTR,PCWSTR,ULONG,PVOID,ULONG);
NTSTATUS NTAPI NtOpenKey(PHANDLE,ACCESS_MASK,POBJECT_ATTRIBUTES);
NTSTATUS NTAPI NtDeleteKey(HANDLE);
NTSTATUS NTAPI RtlAdjustPrivilege(ULONG,BOOLEAN,BOOLEAN,PBOOLEAN);


