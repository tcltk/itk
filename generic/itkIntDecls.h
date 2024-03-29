
/* !BEGIN!: Do not edit below this line. */

#define ITKINT_STUBS_EPOCH 0
#define ITKINT_STUBS_REVISION 17

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Exported function declarations:
 */

/* Slot 0 is reserved */
/* Slot 1 is reserved */
/* 2 */
ITKAPI int		Itk_ConfigBodyCmd(ClientData cdata,
				Tcl_Interp *interp, int objc,
				Tcl_Obj *const objv[]);
/* 3 */
ITKAPI int		Itk_UsualCmd(ClientData cdata, Tcl_Interp *interp,
				int objc, Tcl_Obj *const objv[]);
/* 4 */
ITKAPI int		Itk_ClassOptionDefineCmd(ClientData cdata,
				Tcl_Interp *interp, int objc,
				Tcl_Obj *const objv[]);
/* 5 */
ITKAPI int		Itk_ClassOptionIllegalCmd(ClientData cdata,
				Tcl_Interp *interp, int objc,
				Tcl_Obj *const objv[]);
/* 6 */
ITKAPI int		Itk_ConfigClassOption(Tcl_Interp *interp,
				ItclObject *contextObj, ClientData cdata,
				const char*newVal);
/* 7 */
ITKAPI ItkClassOptTable* Itk_CreateClassOptTable(Tcl_Interp *interp,
				ItclClass *cdefn);
/* 8 */
ITKAPI ItkClassOptTable* Itk_FindClassOptTable(ItclClass *cdefn);
/* Slot 9 is reserved */
/* 10 */
ITKAPI int		Itk_CreateClassOption(Tcl_Interp *interp,
				ItclClass *cdefn, char *switchName,
				char *resName, char *resClass, char *defVal,
				char *config, ItkClassOption **optPtr);
/* 11 */
ITKAPI ItkClassOption*	Itk_FindClassOption(ItclClass *cdefn,
				const char *switchName);
/* 12 */
ITKAPI void		Itk_DelClassOption(ItkClassOption *opt);
/* Slot 13 is reserved */
/* 14 */
ITKAPI void		Itk_OptListInit(ItkOptList*olist,
				Tcl_HashTable *options);
/* 15 */
ITKAPI void		Itk_OptListFree(ItkOptList*olist);
/* 16 */
ITKAPI void		Itk_OptListAdd(ItkOptList*olist,
				Tcl_HashEntry *entry);
/* 17 */
ITKAPI void		Itk_OptListRemove(ItkOptList*olist,
				Tcl_HashEntry *entry);

typedef struct ItkIntStubs {
    int magic;
    int epoch;
    int revision;
    void *hooks;

    void (*reserved0)(void);
    void (*reserved1)(void);
    int (*itk_ConfigBodyCmd) (ClientData cdata, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[]); /* 2 */
    int (*itk_UsualCmd) (ClientData cdata, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[]); /* 3 */
    int (*itk_ClassOptionDefineCmd) (ClientData cdata, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[]); /* 4 */
    int (*itk_ClassOptionIllegalCmd) (ClientData cdata, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[]); /* 5 */
    int (*itk_ConfigClassOption) (Tcl_Interp *interp, ItclObject *contextObj, ClientData cdata, const char*newVal); /* 6 */
    ItkClassOptTable* (*itk_CreateClassOptTable) (Tcl_Interp *interp, ItclClass *cdefn); /* 7 */
    ItkClassOptTable* (*itk_FindClassOptTable) (ItclClass *cdefn); /* 8 */
    void (*reserved9)(void);
    int (*itk_CreateClassOption) (Tcl_Interp *interp, ItclClass *cdefn, char *switchName, char *resName, char *resClass, char *defVal, char *config, ItkClassOption **optPtr); /* 10 */
    ItkClassOption* (*itk_FindClassOption) (ItclClass *cdefn, const char *switchName); /* 11 */
    void (*itk_DelClassOption) (ItkClassOption *opt); /* 12 */
    void (*reserved13)(void);
    void (*itk_OptListInit) (ItkOptList*olist, Tcl_HashTable *options); /* 14 */
    void (*itk_OptListFree) (ItkOptList*olist); /* 15 */
    void (*itk_OptListAdd) (ItkOptList*olist, Tcl_HashEntry *entry); /* 16 */
    void (*itk_OptListRemove) (ItkOptList*olist, Tcl_HashEntry *entry); /* 17 */
} ItkIntStubs;

extern const ItkIntStubs *itkIntStubsPtr;

#ifdef __cplusplus
}
#endif

#if defined(USE_ITK_STUBS)

/*
 * Inline function declarations:
 */

/* Slot 0 is reserved */
/* Slot 1 is reserved */
#define Itk_ConfigBodyCmd \
	(itkIntStubsPtr->itk_ConfigBodyCmd) /* 2 */
#define Itk_UsualCmd \
	(itkIntStubsPtr->itk_UsualCmd) /* 3 */
#define Itk_ClassOptionDefineCmd \
	(itkIntStubsPtr->itk_ClassOptionDefineCmd) /* 4 */
#define Itk_ClassOptionIllegalCmd \
	(itkIntStubsPtr->itk_ClassOptionIllegalCmd) /* 5 */
#define Itk_ConfigClassOption \
	(itkIntStubsPtr->itk_ConfigClassOption) /* 6 */
#define Itk_CreateClassOptTable \
	(itkIntStubsPtr->itk_CreateClassOptTable) /* 7 */
#define Itk_FindClassOptTable \
	(itkIntStubsPtr->itk_FindClassOptTable) /* 8 */
/* Slot 9 is reserved */
#define Itk_CreateClassOption \
	(itkIntStubsPtr->itk_CreateClassOption) /* 10 */
#define Itk_FindClassOption \
	(itkIntStubsPtr->itk_FindClassOption) /* 11 */
#define Itk_DelClassOption \
	(itkIntStubsPtr->itk_DelClassOption) /* 12 */
/* Slot 13 is reserved */
#define Itk_OptListInit \
	(itkIntStubsPtr->itk_OptListInit) /* 14 */
#define Itk_OptListFree \
	(itkIntStubsPtr->itk_OptListFree) /* 15 */
#define Itk_OptListAdd \
	(itkIntStubsPtr->itk_OptListAdd) /* 16 */
#define Itk_OptListRemove \
	(itkIntStubsPtr->itk_OptListRemove) /* 17 */

#endif /* defined(USE_ITK_STUBS) */

/* !END!: Do not edit above this line. */

struct ItkStubAPI {
    ItkStubs *stubsPtr;
    ItkIntStubs *intStubsPtr;
};

