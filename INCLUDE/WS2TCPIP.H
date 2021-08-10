/*
**  WS2TCPIP.H - WinSock2 Extension for TCP/IP protocols
**
**  This file contains TCP/IP specific information for use
**  by WinSock2 compatible applications.
**
** Copyright (c) Microsoft Corporation. All rights reserved.
**
**  To provide the backward compatibility, all the TCP/IP
**  specific definitions that were included in the WINSOCK.H
**   file are now included in WINSOCK2.H file. WS2TCPIP.H
**  file includes only the definitions  introduced in the
**  "WinSock 2 Protocol-Specific Annex" document.
**
**  Rev 0.3 Nov 13, 1995
**      Rev 0.4 Dec 15, 1996
*/

#ifndef _WS2TCPIP_H_
#define _WS2TCPIP_H_

#if _MSC_VER > 1000
#pragma once
#endif

/* Argument structure for IP_ADD_MEMBERSHIP and IP_DROP_MEMBERSHIP */

struct ip_mreq {
    struct in_addr imr_multiaddr;   /* IP multicast address of group */
    struct in_addr imr_interface;   /* local IP address of interface */
};

/* Argument structure for IP_ADD_SOURCE_MEMBERSHIP, IP_DROP_SOURCE_MEMBERSHIP,
 * IP_BLOCK_SOURCE, and IP_UNBLOCK_SOURCE
 */

struct ip_mreq_source {
    struct in_addr imr_multiaddr;   /* IP multicast address of group */
    struct in_addr imr_sourceaddr;  /* IP address of source          */
    struct in_addr imr_interface;   /* local IP address of interface */
};

/* Argument structure for SIO_{GET,SET}_MULTICAST_FILTER */

struct ip_msfilter {
    struct in_addr imsf_multiaddr;  /* IP multicast address of group */
    struct in_addr imsf_interface;  /* local IP address of interface */
    u_long         imsf_fmode;      /* filter mode - INCLUDE or EXCLUDE */
    u_long         imsf_numsrc;     /* number of sources in src_list */
    struct in_addr imsf_slist[1];
};

#define IP_MSFILTER_SIZE(numsrc) \
    (sizeof(struct ip_msfilter)-sizeof(struct in_addr) + (numsrc)*sizeof(struct in_addr))

#define MCAST_INCLUDE 0
#define MCAST_EXCLUDE 1

/* TCP/IP specific Ioctl codes */

#define SIO_GET_INTERFACE_LIST  _IOR('t', 127, u_long)
/* New IOCTL with address size independent address array */
#define SIO_GET_INTERFACE_LIST_EX  _IOR('t', 126, u_long)
#define SIO_SET_MULTICAST_FILTER   _IOW('t', 125, u_long)
#define SIO_GET_MULTICAST_FILTER   _IOW('t', 124 | IOC_IN, u_long)

/* Option to use with [gs]etsockopt at the IPPROTO_IP level */

#define IP_OPTIONS      1 /* set/get IP options */
#define IP_HDRINCL      2 /* header is included with data */
#define IP_TOS          3 /* IP type of service and preced*/
#define IP_TTL          4 /* IP time to live */
#define IP_MULTICAST_IF     9 /* set/get IP multicast i/f  */
#define IP_MULTICAST_TTL       10 /* set/get IP multicast ttl */
#define IP_MULTICAST_LOOP      11 /*set/get IP multicast loopback */
#define IP_ADD_MEMBERSHIP      12 /* add an IP group membership */
#define IP_DROP_MEMBERSHIP     13/* drop an IP group membership */
#define IP_DONTFRAGMENT     14 /* don't fragment IP datagrams */
#define IP_ADD_SOURCE_MEMBERSHIP  15 /* join IP group/source */
#define IP_DROP_SOURCE_MEMBERSHIP 16 /* leave IP group/source */
#define IP_BLOCK_SOURCE           17 /* block IP group/source */
#define IP_UNBLOCK_SOURCE         18 /* unblock IP group/source */
#define IP_PKTINFO                19 /* receive packet information for ipv4*/

/* Option to use with [gs]etsockopt at the IPPROTO_IPV6 level */

#define IPV6_HDRINCL            2  /* Header is included with data */
#define IPV6_UNICAST_HOPS       4  /* Set/get IP unicast hop limit */
#define IPV6_MULTICAST_IF       9  /* Set/get IP multicast interface */
#define IPV6_MULTICAST_HOPS     10 /* Set/get IP multicast ttl */
#define IPV6_MULTICAST_LOOP     11 /* Set/get IP multicast loopback */
#define IPV6_ADD_MEMBERSHIP     12 /* Add an IP group membership */
#define IPV6_DROP_MEMBERSHIP    13 /* Drop an IP group membership */
#define IPV6_JOIN_GROUP         IPV6_ADD_MEMBERSHIP
#define IPV6_LEAVE_GROUP        IPV6_DROP_MEMBERSHIP
#define IPV6_PKTINFO            19 /* Receive packet information for ipv6 */


/* Option to use with [gs]etsockopt at the IPPROTO_UDP level */

#define UDP_NOCHECKSUM  1
#define UDP_CHECKSUM_COVERAGE   20  /* Set/get UDP-Lite checksum coverage */

/* Option to use with [gs]etsockopt at the IPPROTO_TCP level */

#define  TCP_EXPEDITED_1122 0x0002


/* IPv6 definitions */

#ifndef s6_addr

struct in6_addr {
    union {
        u_char Byte[16];
        u_short Word[8];
    } u;
};

#define in_addr6 in6_addr

/*
** Defines to match RFC 2553.
*/
#define _S6_un     u
#define _S6_u8     Byte
#define s6_addr    _S6_un._S6_u8

/*
** Defines for our implementation.
*/
#define s6_bytes   u.Byte
#define s6_words   u.Word

#endif

/* Argument structure for IPV6_JOIN_GROUP and IPV6_LEAVE_GROUP */

typedef struct ipv6_mreq {
    struct in6_addr ipv6mr_multiaddr;  /* IPv6 multicast address */
    unsigned int    ipv6mr_interface;  /* Interface index */
} IPV6_MREQ;


/* Old IPv6 socket address structure (retained for sockaddr_gen definition below) */

struct sockaddr_in6_old {
                short   sin6_family;    /* AF_INET6 */
                u_short sin6_port;      /* Transport level port number */
                u_long  sin6_flowinfo;  /* IPv6 flow information */
                struct in6_addr sin6_addr; /* IPv6 address */
};

/* IPv6 socket address structure, RFC 2553 */

struct sockaddr_in6 {
                short   sin6_family;    /* AF_INET6 */
                u_short sin6_port;      /* Transport level port number */
                u_long  sin6_flowinfo;  /* IPv6 flow information */
                struct in6_addr sin6_addr; /* IPv6 address */
        u_long sin6_scope_id;  /* set of interfaces for a scope */
};


typedef struct in6_addr IN6_ADDR;
typedef struct in6_addr *PIN6_ADDR;
typedef struct in6_addr FAR *LPIN6_ADDR;

typedef struct sockaddr_in6 SOCKADDR_IN6;
typedef struct sockaddr_in6 *PSOCKADDR_IN6;
typedef struct sockaddr_in6 FAR *LPSOCKADDR_IN6;

/* Macro that works for both IPv4 and IPv6 */
#define SS_PORT(ssp) (((struct sockaddr_in*)(ssp))->sin_port)

#define IN6ADDR_ANY_INIT        { 0 }
#define IN6ADDR_LOOPBACK_INIT   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#ifdef  __cplusplus
extern "C" {
#endif

extern const struct in6_addr in6addr_any;
extern const struct in6_addr in6addr_loopback;

#ifdef  __cplusplus
}
#endif

#ifdef _MSC_VER
#define WS2TCPIP_INLINE __inline
#else
#define WS2TCPIP_INLINE extern inline /* GNU style */
#endif

#define IN6ADDR_SETANY(x) {\
(x)->sin6_family = AF_INET6; \
(x)->sin6_port = 0; \
(x)->sin6_flowinfo = 0; \
*((u_long *)((x)->sin6_addr.s6_addr)    ) = 0; \
*((u_long *)((x)->sin6_addr.s6_addr) + 1) = 0; \
*((u_long *)((x)->sin6_addr.s6_addr) + 2) = 0; \
*((u_long *)((x)->sin6_addr.s6_addr) + 3) = 0; \
}
#define IN6ADDR_SETLOOPBACK(x) {\
(x)->sin6_family = AF_INET6; \
(x)->sin6_port = 0; \
(x)->sin6_flowinfo = 0; \
*((u_long *)((x)->sin6_addr.s6_addr)    ) = 0; \
*((u_long *)((x)->sin6_addr.s6_addr) + 1) = 0; \
*((u_long *)((x)->sin6_addr.s6_addr) + 2) = 0; \
*((u_long *)((x)->sin6_addr.s6_addr) + 3) = 1; \
}

#define IN6ADDR_ISANY(x) ( \
(x)->sin6_family == AF_INET6 && \
*((u_long *)((x)->sin6_addr.s6_addr)    ) == 0 && \
*((u_long *)((x)->sin6_addr.s6_addr) + 1) == 0 && \
*((u_long *)((x)->sin6_addr.s6_addr) + 2) == 0 && \
*((u_long *)((x)->sin6_addr.s6_addr) + 3) == 0 \
)


#define IN6ADDR_ISLOOPBACK(x) (\
(x)->sin6_family == AF_INET6 && \
*((u_long *)((x)->sin6_addr.s6_addr)    ) == 0 && \
*((u_long *)((x)->sin6_addr.s6_addr) + 1) == 0 && \
*((u_long *)((x)->sin6_addr.s6_addr) + 2) == 0 && \
*((u_long *)((x)->sin6_addr.s6_addr) + 3) == 1 \
)

WS2TCPIP_INLINE int
IN6_ADDR_EQUAL(const struct in6_addr *a, const struct in6_addr *b)
{
    return (memcmp(a, b, sizeof(struct in6_addr)) == 0);
}

#define IN6_IS_ADDR_UNSPECIFIED(a) IN6_ADDR_EQUAL((a), &in6addr_any)
#define IN6_IS_ADDR_LOOPBACK(a)    IN6_ADDR_EQUAL((a), &in6addr_loopback)

WS2TCPIP_INLINE int
IN6_IS_ADDR_MULTICAST(const struct in6_addr *a)
{
    return (a->s6_bytes[0] == 0xff);
}

WS2TCPIP_INLINE int
IN6_IS_ADDR_LINKLOCAL(const struct in6_addr *a)
{
    return ((a->s6_bytes[0] == 0xfe) &&
            ((a->s6_bytes[1] & 0xc0) == 0x80));
}

WS2TCPIP_INLINE int
IN6_IS_ADDR_SITELOCAL(const struct in6_addr *a)
{
    return ((a->s6_bytes[0] == 0xfe) &&
            ((a->s6_bytes[1] & 0xc0) == 0xc0));
}

WS2TCPIP_INLINE int
IN6_IS_ADDR_V4MAPPED(const struct in6_addr *a)
{
    return ((a->s6_words[0] == 0) &&
            (a->s6_words[1] == 0) &&
            (a->s6_words[2] == 0) &&
            (a->s6_words[3] == 0) &&
            (a->s6_words[4] == 0) &&
            (a->s6_words[5] == 0xffff));
}

WS2TCPIP_INLINE int
IN6_IS_ADDR_V4COMPAT(const struct in6_addr *a)
{
    return ((a->s6_words[0] == 0) &&
            (a->s6_words[1] == 0) &&
            (a->s6_words[2] == 0) &&
            (a->s6_words[3] == 0) &&
            (a->s6_words[4] == 0) &&
            (a->s6_words[5] == 0) &&
            !((a->s6_words[6] == 0) &&
              (a->s6_addr[14] == 0) &&
             ((a->s6_addr[15] == 0) || (a->s6_addr[15] == 1))));
}

WS2TCPIP_INLINE int
IN6_IS_ADDR_MC_NODELOCAL(const struct in6_addr *a)
{
    return IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf) == 1);
}

WS2TCPIP_INLINE int
IN6_IS_ADDR_MC_LINKLOCAL(const struct in6_addr *a)
{
    return IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf) == 2);
}

WS2TCPIP_INLINE int
IN6_IS_ADDR_MC_SITELOCAL(const struct in6_addr *a)
{
    return IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf) == 5);
}

WS2TCPIP_INLINE int
IN6_IS_ADDR_MC_ORGLOCAL(const struct in6_addr *a)
{
    return IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf) == 8);
}

WS2TCPIP_INLINE int
IN6_IS_ADDR_MC_GLOBAL(const struct in6_addr *a)
{
    return IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf) == 0xe);
}

typedef union sockaddr_gen{
        struct sockaddr Address;
        struct sockaddr_in  AddressIn;
        struct sockaddr_in6_old AddressIn6;
} sockaddr_gen;

/* Structure to keep interface specific information */

typedef struct _INTERFACE_INFO
{
    u_long      iiFlags;        /* Interface flags */
    sockaddr_gen    iiAddress;      /* Interface address */
    sockaddr_gen    iiBroadcastAddress;     /* Broadcast address */
    sockaddr_gen    iiNetmask;      /* Network mask */
} INTERFACE_INFO, FAR * LPINTERFACE_INFO;

/* New structure that does not have dependency on the address size */
typedef struct _INTERFACE_INFO_EX
{
    u_long      iiFlags;        /* Interface flags */
    SOCKET_ADDRESS  iiAddress;          /* Interface address */
    SOCKET_ADDRESS  iiBroadcastAddress; /* Broadcast address */
    SOCKET_ADDRESS  iiNetmask;          /* Network mask */
} INTERFACE_INFO_EX, FAR * LPINTERFACE_INFO_EX;

/* Possible flags for the  iiFlags - bitmask  */

#define IFF_UP      0x00000001 /* Interface is up */
#define IFF_BROADCAST   0x00000002 /* Broadcast is  supported */
#define IFF_LOOPBACK    0x00000004 /* this is loopback interface */
#define IFF_POINTTOPOINT 0x00000008 /*this is point-to-point interface*/
#define IFF_MULTICAST   0x00000010 /* multicast is supported */


// structure for IP_PKTINFO option
//
typedef struct in_pktinfo {
    IN_ADDR ipi_addr; // destination IPv4 address
    UINT    ipi_ifindex; // received interface index
} IN_PKTINFO;

C_ASSERT(sizeof(IN_PKTINFO) == 8);

// structure for IPV6_PKTINFO option
//
typedef struct in6_pktinfo {
    IN6_ADDR ipi6_addr; // destination IPv6 address
    UINT     ipi6_ifindex; // received interface index
} IN6_PKTINFO;

C_ASSERT(sizeof(IN6_PKTINFO) == 20);

/* Error codes from getaddrinfo() */

#define EAI_AGAIN       WSATRY_AGAIN
#define EAI_BADFLAGS    WSAEINVAL
#define EAI_FAIL        WSANO_RECOVERY
#define EAI_FAMILY      WSAEAFNOSUPPORT
#define EAI_MEMORY      WSA_NOT_ENOUGH_MEMORY
//#define EAI_NODATA      WSANO_DATA
#define EAI_NONAME      WSAHOST_NOT_FOUND
#define EAI_SERVICE     WSATYPE_NOT_FOUND
#define EAI_SOCKTYPE    WSAESOCKTNOSUPPORT

//
//  DCR_FIX:  EAI_NODATA remove or fix
//
//  EAI_NODATA was removed from rfc2553bis
//  need to find out from the authors why and
//  determine the error for "no records of this type"
//  temporarily, we'll keep #define to avoid changing
//  code that could change back;  use NONAME
//

#define EAI_NODATA      EAI_NONAME



/* Structure used in getaddrinfo() call */

typedef struct addrinfo {
    int ai_flags;              /* AI_PASSIVE, AI_CANONNAME, AI_NUMERICHOST */
    int ai_family;             /* PF_xxx */
    int ai_socktype;           /* SOCK_xxx */
    int ai_protocol;           /* 0 or IPPROTO_xxx for IPv4 and IPv6 */
    size_t ai_addrlen;         /* Length of ai_addr */
    char *ai_canonname;        /* Canonical name for nodename */
    struct sockaddr *ai_addr;  /* Binary address */
    struct addrinfo *ai_next;  /* Next structure in linked list */
} ADDRINFO, FAR * LPADDRINFO;


/* Flags used in "hints" argument to getaddrinfo() */

#define AI_PASSIVE     0x1  /* Socket address will be used in bind() call */
#define AI_CANONNAME   0x2  /* Return canonical name in first ai_canonname */
#define AI_NUMERICHOST 0x4  /* Nodename must be a numeric address string */

#ifdef __cplusplus
extern "C" {
#endif

WINSOCK_API_LINKAGE
int
WSAAPI
getaddrinfo(
    IN const char FAR * nodename,
    IN const char FAR * servname,
    IN const struct addrinfo FAR * hints,
    OUT struct addrinfo FAR * FAR * res
    );

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI * LPFN_GETADDRINFO)(
    IN const char FAR * nodename,
    IN const char FAR * servname,
    IN const struct addrinfo FAR * hints,
    OUT struct addrinfo FAR * FAR * res
    );
#endif

WINSOCK_API_LINKAGE
void
WSAAPI
freeaddrinfo(
    IN struct addrinfo FAR * ai
    );

#if INCL_WINSOCK_API_TYPEDEFS
typedef
void
(WSAAPI * LPFN_FREEADDRINFO)(
    IN struct addrinfo FAR * ai
    );
#endif

#if INCL_WINSOCK_API_PROTOTYPES
#ifdef UNICODE
#define gai_strerror   gai_strerrorW
#else
#define gai_strerror   gai_strerrorA
#endif  /* UNICODE */

// WARNING: The gai_strerror inline functions below use static buffers,
// and hence are not thread-safe.  We'll use buffers long enough to hold
// 1k characters.  Any system error messages longer than this will be
// returned as empty strings.  However 1k should work for the error codes
// used by getaddrinfo().
#define GAI_STRERROR_BUFFER_SIZE 1024

WS2TCPIP_INLINE
char *
gai_strerrorA(
    IN int ecode)
{
    DWORD dwMsgLen;
    static char buff[GAI_STRERROR_BUFFER_SIZE + 1];

    dwMsgLen = FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM
                             |FORMAT_MESSAGE_IGNORE_INSERTS
                             |FORMAT_MESSAGE_MAX_WIDTH_MASK,
                              NULL,
                              ecode,
                              MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                              (LPSTR)buff,
                              GAI_STRERROR_BUFFER_SIZE,
                              NULL);

    return buff;
}

WS2TCPIP_INLINE
WCHAR *
gai_strerrorW(
    IN int ecode
    )
{
    DWORD dwMsgLen;
    static WCHAR buff[GAI_STRERROR_BUFFER_SIZE + 1];

    dwMsgLen = FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM
                             |FORMAT_MESSAGE_IGNORE_INSERTS
                             |FORMAT_MESSAGE_MAX_WIDTH_MASK,
                              NULL,
                              ecode,
                              MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                              (LPWSTR)buff,
                              GAI_STRERROR_BUFFER_SIZE,
                              NULL);

    return buff;
}
#endif /* INCL_WINSOCK_API_PROTOTYPES */

typedef int socklen_t;

WINSOCK_API_LINKAGE
int
WSAAPI
getnameinfo(
    IN  const struct sockaddr FAR * sa,
    IN  socklen_t       salen,
    OUT char FAR *      host,
    IN  DWORD           hostlen,
    OUT char FAR *      serv,
    IN  DWORD           servlen,
    IN  int             flags
    );

#if INCL_WINSOCK_API_TYPEDEFS
typedef
int
(WSAAPI * LPFN_GETNAMEINFO)(
    IN  const struct sockaddr FAR * sa,
    IN  socklen_t       salen,
    OUT char FAR *      host,
    IN  DWORD           hostlen,
    OUT char FAR *      serv,
    IN  DWORD           servlen,
    IN  int             flags
    );
#endif


#define NI_MAXHOST  1025  /* Max size of a fully-qualified domain name */
#define NI_MAXSERV    32  /* Max size of a service name */

#define INET_ADDRSTRLEN  16 /* Max size of numeric form of IPv4 address */
#define INET6_ADDRSTRLEN 46 /* Max size of numeric form of IPv6 address */

/* Flags for getnameinfo() */

#define NI_NOFQDN       0x01  /* Only return nodename portion for local hosts */
#define NI_NUMERICHOST  0x02  /* Return numeric form of the host's address */
#define NI_NAMEREQD     0x04  /* Error if the host's name not in DNS */
#define NI_NUMERICSERV  0x08  /* Return numeric form of the service (port #) */
#define NI_DGRAM        0x10  /* Service is a datagram service */

#ifdef __cplusplus
}
#endif

//
// Unless the build environment is explicitly targeting only
// platforms that include built-in getaddrinfo() support, include
// the backwards-compatibility version of the relevant APIs.
//
#if !defined(_WIN32_WINNT) || (_WIN32_WINNT <= 0x0500)
#include <wspiapi.h>
#endif

#endif  /* _WS2TCPIP_H_ */
