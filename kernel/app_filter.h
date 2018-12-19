#ifndef APP_FILTER_H
#define APP_FILTER_H
#define AF_DEBUG printk
#define AF_ERROR printk
#define AF_INFO printk
#define AF_VERSION "1.0.1"
//#define CONFIG_KERNEL_FUNC_TEST 1

#define HTTP_GET_METHOD_STR "GET"
#define HTTP_POST_METHOD_STR "POST"
#define HTTP_HEADER "HTTP"
#define NIPQUAD(addr) \
	((unsigned char *)&addr)[0], \
	((unsigned char *)&addr)[1], \
	((unsigned char *)&addr)[2], \
	((unsigned char *)&addr)[3]
#define NIPQUAD_FMT "%u.%u.%u.%u"

#define AF_TRUE 1
#define AF_FALSE 0

#define HTTPS_URL_OFFSET		9
#define HTTPS_LEN_OFFSET		7

enum e_http_method{
	HTTP_METHOD_GET = 1,
	HTTP_METHOD_POST,
};
typedef struct http_proto{
	int match;
	int method;
	char *url_pos;
	int url_len;
	char *host_pos;
	int host_len;
	char *data_pos;
	int data_len;
}http_proto_t;

typedef struct https_proto{
	int match;
	char *url_pos;
	int url_len;
}https_proto_t;

typedef struct flow_info{
	struct nf_conn *ct; // ���Ӹ���ָ��
	u_int32_t src; 
	u_int32_t dst;
	int l4_protocol;
	u_int16_t sport;
	u_int16_t dport;
	unsigned char *l4_data;
	int l4_len;
	http_proto_t http;
	https_proto_t https;
}flow_info_t;

#endif
