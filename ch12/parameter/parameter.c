/*
 * Note: this file originally auto-generated by mib2c using
 * mib2c.old-api-refactor.conf Sat Oct 11 17:57:43 2014
 * zhangchunqiang 2014-10
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "parameter.h"


/* other module head file please */


/*
 * parameter_variables_oid:
 *   this is the top level oid that we want to register under.  This
 *   is essentially a prefix, with the suffix appearing in the
 *   variable below.
 */
oid parameter_variables_oid[] = { 1,3,6,1,4,1,8072,9999,9999,1,2 };

#define PARAMETER_FATHERNODE_LENTH    (sizeof(parameter_variables_oid) / sizeof(oid) )


/*
 * variable4 parameter_variables:
 *   this variable defines function callbacks and type return information
 *   for the parameter mib section
 */
struct variable4 parameter_variables[] = {
/*  magic number        , variable type , ro/rw , callback fn  , L, oidsuffix */
	{PARAMETERA,  ASN_INTEGER,  NETSNMP_OLDAPI_RWRITE,  var_parameter, 1,  { 1 }},
	{PARAMETERB,  ASN_OCTET_STR,  NETSNMP_OLDAPI_RWRITE,  var_parameter, 1,  { 2 }},

	{PARAMETERINDEX,  ASN_INTEGER,  NETSNMP_OLDAPI_RONLY,   var_parameterTable, 3,  { 3, 1, 1 }},
	{PARAMETERC1,  ASN_INTEGER,  NETSNMP_OLDAPI_RWRITE,  var_parameterTable, 3,  { 3, 1, 2 }},
	{0,0,0,NULL,0,0} //added for find only
};

/*******************************************************
   通过oid查找magic
 ********************************************************/
static int find_magic_parameter(const oid *name,int namelen)
{
 	return 
 		find_magic(name,namelen,
 		     PARAMETER_FATHERNODE_LENTH, parameter_variables);
}
/*
 * the int Num you may used in initialization
 * and the '0' you may need replace with right data;
 * NOTICE: this Num may not need sometimes,eg,they are from other module
 * or they maybe as the globle data so please copy to the parameter.h
 */
int gi_parameterTableNum = C_ROW_NUM;

/*
 * the gp_xxxHead is the list head you should initialize
 * and use in the iteratoration to find the right node data.
 */
T_TableSimple  *gp_parameterTableHead = NULL;

/*
 * for all scalar node :tacheID define
 * that is your business now:
 * fill it with your No.
 * and check the MAGICs
 */
static MIBIDSTRUCT gt_parameterScalarIDMap[]  ={
	/*No.,  MAGIC*/

	{ .t_tacheID.ipcNo = PARA_A,.t_tacheID.snmpmagic = PARAMETERA,.asnType=ASN_INTEGER},
	{ .t_tacheID.ipcNo = PARA_B,.t_tacheID.snmpmagic =PARAMETERB,.asnType=ASN_OCTET_STR}
};

#define SCALAR_PARAMETER_NUM  (sizeof(gt_parameterScalarIDMap) /sizeof(T_SNMPMapTable))

/*
 * check the table index need or not !!
 * for table object :tacheID define
 * that is your business now:
 * fill it with your No.
 * and check the MAGICs
 */

static MIBIDSTRUCT gt_parameterTableIDMap[] = {
	{ .t_tacheID.ipcNo = PARA_C1,.t_tacheID.snmpmagic = PARAMETERC1,.asnType=ASN_INTEGER},
};
#define PARAMETERTABLE_COLNUM  (sizeof(gt_parameterTableIDMap) /sizeof(T_SNMPMapTable))


/*******************************************************
   通过行号和magic返回对应的节点
 ********************************************************/
static MIBIDSTRUCT  *
get_table_node_parameterTable( const oid *name,int name_len)//(int rowIndex, const int magic)
{

	// 首先，搜索请求节点的magic
	int magic = find_magic_parameter(name,name_len);

	return
	    get_table_node(gp_parameterTableHead,
	                  PARAMETERTABLE_COLNUM,name[name_len - 1],
	                  magic );
}

/*******************************************************
   通过行号和magic返回对应的节点
 ********************************************************/
static MIBIDSTRUCT  *
get_table_node_parameterTable_withmagic( int rowIndex,int magic )//(int rowIndex, const int magic)
{
	return
	    get_table_node(gp_parameterTableHead,
	                  PARAMETERTABLE_COLNUM,rowIndex,
	                  magic );
}

/*******************************************************
   检查行索引是否越界
 ********************************************************/
static int check_row_index_parameterTable(int index)
{
	if( (index-1) > gi_parameterTableNum)
		return FAILURE;
	return SUCCESS;
}



/*table initial*/
void init_table_parameter(void)
{
	init_nonindex_table(&gp_parameterTableHead, gt_parameterTableIDMap,
	                    PARAMETERTABLE_COLNUM,gi_parameterTableNum);
/*initialize other table that can not initialize by init_noIndexTable*/
}

/** Initializes the parameter module */
void
init_parameter(void)
{
	DEBUGMSGTL(("parameter", "Initializing\n"));
	/* register ourselves with the agent to handle our mib tree */
	REGISTER_MIB("parameter", parameter_variables, variable4,
	             parameter_variables_oid);

	/* place any other initialization junk you need here */
	init_shm_sem_slave();
	init_table_parameter();
}


/*******************************************************
   通过magic找到对应的参数类数据节点
 ********************************************************/
static MIBIDSTRUCT  *get_parameter_scalar_obj(int magic)
{
	return
	    get_scalar_object(gt_parameterScalarIDMap,
	                      SCALAR_PARAMETER_NUM, magic);
}


/*******************************************************
   函数返回值的字节长度；通过序号找到对应的值
 ********************************************************/
static int snmp_get_data_parameter(MIBIDSTRUCT *pN,void *pV)
{
	if( NULL != pN && NULL != pV)
		if( snmp_get_data(SHM_PARAMETER,pN->t_tacheID.ipcNo,MAX_CHAR_LEN,pV) >0 )
			return get_data_length( pN,pV );
	return 0;
}



/*******************************************************
   通过OID返回节点和返回对应的节点ASN类型
 ********************************************************/
static MIBIDSTRUCT *
get_scalar_node_parameter(const oid *name,int namelen)
{
	return
	    get_scalar_node(name,namelen,
	                        PARAMETER_FATHERNODE_LENTH,
	                        parameter_variables,
	                        gt_parameterScalarIDMap,
	                        SCALAR_PARAMETER_NUM);
}

/*******************************************************
   写标量和表格对象
 ********************************************************/
static int snmp_write_action_parameter(int action, u_char snmpType,
                      int var_val_len, u_char * var_val,
                      const MIBIDSTRUCT  *writeNode)
{
	return 
		snmp_write_action(action, snmpType,
	                              var_val_len, var_val,writeNode,SHM_PARAMETER);

}
/*
 * var_parameter():
 *   This function is called every time the agent gets a request for
 *   a scalar variable that might be found within your mib section
 *   registered above.  It is up to you to do the right thing and
 *   return the correct value.
 *     You should also correct the value of "var_len" if necessary.
 *
 *   Please see the documentation for more information about writing
 *   module extensions, and check out the examples in the examples
 *   and mibII directories.
 */
unsigned char *
var_parameter(struct variable *vp,
              oid     *name,
              size_t  *length,
              int exact,
              size_t  *var_len,
              WriteMethod **write_method)
{
	static u_char VAR[MAX_CHAR_LEN]={0};
	MIBIDSTRUCT      *p_getNode = NULL;

	if (header_generic(vp, name, length, exact, var_len, write_method)
	    == MATCH_FAILED)
		return NULL;

	/* 我们替换掉switch结构
	   首先，根据magic查找请求的节点*/
	p_getNode = get_parameter_scalar_obj(vp->magic);

	/* 如果对象可写，则赋值设置函数 */
	if(vp->acl == NETSNMP_OLDAPI_RWRITE)
		*write_method = write_parameter_scalar;

	/*  最后返回获取的数据 */
	*var_len = snmp_get_data_parameter(p_getNode,VAR) ;
	DEBUGMSG(("parameter"," --No.=%d,len=%d\n ",p_getNode->t_tacheID.ipcNo,*var_len));
	 if( *var_len > 0 )
		return VAR;
	return NULL;
}


/*******************************************************
   简化写操作:找到指定的节点，执行设置操作
 ********************************************************/
 /*
原来每个可写对象都独立对应一个设置函数,这样设置请求到来时只要
直接执行设置操作即可。
如今我们准备将所有的设置函数都统一为单个函数，如此，我们必须
根据请求的OID，查找到对应的节点。这个功能需要我们额外的去实现!
为此我们可以定义一个统一查找OID的函数:
get_scalar_node_parameter；
查找的步骤分为 先查找到该OID的MAGIC
接着再查找该MAGIC对应的内部节点

*/
int write_parameter_scalar(int action,
                           u_char * var_val,
                           u_char var_val_type,
                           size_t var_val_len,
                           u_char * statP, oid * name, size_t name_len)
{

	MIBIDSTRUCT       *p_writeNode = NULL;

	if(action == RESERVE1 || action == ACTION || action == COMMIT) //reduce execute times
	{
		//DEBUGMSGOID(("parameter", name, name_len));

		// 首先，搜索指定的节点
		p_writeNode =
		        get_scalar_node_parameter(name,name_len);

		// 如果没有找到任何节点，返回错误标识
		if(p_writeNode == NULL)
		{
			DEBUGMSG(("parameter"," \n--in write_parameter_scalar,return NULL node !!\n "));
			return SNMP_ERR_WRONGENCODING;
		}
	}

	// 最后执行设置操作
	return
		snmp_write_action_parameter(action, var_val_type,
	                                var_val_len, var_val,p_writeNode);
}


/*
 * var_parameterTable():
 *   Handle this table separately from the scalar value case.
 *   The workings of this are basically the same as for var_parameter above.
 */
unsigned char *
var_parameterTable(struct variable *vp,
                   oid     *name,
                   size_t  *length,
                   int exact,
                   size_t  *var_len,
                   WriteMethod **write_method)
{
	//int index = 0;
	//static int idx = 0;
	static u_char VAR[MAX_CHAR_LEN]={0};
	MIBIDSTRUCT      *p_getNode = NULL;

	/*
	 * This assumes that the table is a 'simple' table.
	 *	See the implementation documentation for the meaning of this.
	 *	You will need to provide the correct value for the gi_parameterTableNum
	 *
	 * If this table does not meet the requirements for a simple table,
	 *	you will need to provide the replacement code yourself.
	 *	Mib2c is not smart enough to write this for you.
	 *    Again, see the implementation documentation for what is required.
	 */
	if (header_simple_table(vp,name,length,exact,var_len,write_method,gi_parameterTableNum)
	    == MATCH_FAILED)
		return NULL;

	if(FAILURE == check_row_index_parameterTable(name[*length - 1]))
		return NULL;

	DEBUGMSGTL(("parameter", "magic = %d\n",vp->magic));
	/* 我们替换掉switch结构
	   首先，根据magic查找请求的节点*/
	p_getNode =
	        get_table_node_parameterTable_withmagic(name[*length - 1], vp->magic );

	/* 如果没有找到直接返回 */
	if(p_getNode == NULL) return NULL;

	/* 如果对象可写，则赋值设置函数 */
	if(vp->acl == NETSNMP_OLDAPI_RWRITE)
		*write_method = write_parameterTable; // 每个表格统一使用一个写函数

	/*  最后返回获取的数据 */
	*var_len = snmp_get_data_parameter(p_getNode,VAR) ;
	DEBUGMSG(("parameter"," --No.=%d,len=%d\n ",p_getNode->t_tacheID.ipcNo,*var_len));
	 if( *var_len > 0 )
		return VAR;
	return NULL;
}

int
write_parameterTable(int action,
                     u_char   *var_val,
                     u_char var_val_type,
                     size_t var_val_len,
                     u_char   *statP,
                     oid      *name,
                     size_t name_len)
{
	MIBIDSTRUCT      *p_writeNode = NULL;
	//static int type=0;
	//static int magic =0;

	if(action == RESERVE1 || action == ACTION)
	{
		// 首先，搜索请求节点的magic
		//magic = find_magic_parameter(name,name_len);

	      // 首先，搜索指定的节点
		p_writeNode =
				get_table_node_parameterTable( name, name_len );
		 //get_table_node_parameter(name[name_len - 1], magic );
		// 如果没有找到任何节点，返回错误标识
		if(p_writeNode == NULL)
		{
			DEBUGMSG(("parameter"," \n--in write_parameterTable,return NULL node !!\n "));
			return SNMP_ERR_WRONGENCODING;
		}
	}

	// 最后执行设置操作
	return
		snmp_write_action_parameter(action, var_val_type,
	                                var_val_len, var_val,p_writeNode);
}



