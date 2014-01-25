
#define MAX_LINE_SIZE			250
#define MAX_TYPE_SIZE			25
#define MAX_LIST_ENTRIES		65535
#define MAX_HOST_ENTRIES		4000000

#define IPV6_UNSPEC				1
#define IPV6_MULTICAST			2
#define IPV6_UNICAST			4

#define UCAST_V4MAPPED			1
#define UCAST_V4COMPAT			2
#define UCAST_LINKLOCAL			4
#define UCAST_SITELOCAL			8
#define UCAST_UNIQUELOCAL		16
#define UCAST_6TO4				32
#define UCAST_TEREDO			64
#define UCAST_GLOBAL			128
#define UCAST_LOOPBACK			256

#define MCAST_PERMANENT			512
#define MCAST_NONPERMANENT		1024
#define MCAST_INVALID			2048
#define MCAST_UNICASTBASED		4096
#define MCAST_EMBEDRP			8192
#define MCAST_UNKNOWN			16384

#define SCOPE_RESERVED			1
#define SCOPE_INTERFACE			2
#define SCOPE_LINK				4
#define SCOPE_ADMIN				8
#define SCOPE_SITE				16
#define SCOPE_ORGANIZATION		32
#define SCOPE_GLOBAL			64
#define SCOPE_UNASSIGNED		128
#define SCOPE_UNSPECIFIED		256

#define IID_MACDERIVED			1
#define IID_ISATAP				2
#define IID_EMBEDDEDIPV4		4
#define IID_EMBEDDEDPORT		8
#define IID_EMBEDDEDPORTREV		16
#define IID_LOWBYTE				32
#define IID_EMBEDDEDIPV4_64		64
#define IID_PATTERN_BYTES		128
#define IID_RANDOM				256
#define IID_TEREDO_RFC4380		512
#define IID_TEREDO_RFC5991		1024
#define IID_TEREDO_UNKNOWN		2048
#define IID_UNSPECIFIED			4096


/* Filter Constants */
#define MAX_BLOCK			50
#define MAX_ACCEPT			50


struct	decode6{
	struct in6_addr	ip6;
	unsigned int	type;
	unsigned int	subtype;
	unsigned int	scope;
	unsigned int	iidtype;
	unsigned int	iidsubtype;
};


struct stats6{
	unsigned int	total;
	unsigned int	ipv6unspecified;
	unsigned int	ipv6multicast;
	unsigned int	ipv6unicast;

	unsigned int 	ucastloopback;
	unsigned int	ucastv4mapped;
	unsigned int	ucastv4compat;
	unsigned int	ucastlinklocal;
	unsigned int    ucastsitelocal;
	unsigned int	ucastuniquelocal;
	unsigned int	ucast6to4;
	unsigned int	ucastteredo;
	unsigned int	ucastglobal;

	unsigned int	mcastpermanent;
	unsigned int	mcastnonpermanent;
	unsigned int	mcastinvalid;
	unsigned int	mcastunicastbased;
	unsigned int	mcastembedrp;
	unsigned int	mcastunknown;

	unsigned int	iidmacderived;
	unsigned int	iidisatap;
	unsigned int	iidmbeddedipv4;
	unsigned int	iidembeddedport;
	unsigned int	iidembeddedportrev;
	unsigned int	iidlowbyte;
	unsigned int	iidembeddedipv4_64;
	unsigned int	iidpatternbytes;
	unsigned int	iidrandom;

	unsigned int	mscopereserved;
	unsigned int	mscopeinterface;
	unsigned int	mnscopelink;
	unsigned int	mscopeadmin;
	unsigned int	mscopesite;
	unsigned int	mscopeorganization;
	unsigned int	mscopeglobal;
	unsigned int	mscopeunassigned;
	unsigned int	mscopeunspecified;
};

#ifndef IN6_IS_ADDR_UNIQUELOCAL
	#define IN6_IS_ADDR_UNIQUELOCAL(a) \
		((((uint32_t *) (a))[0] & htonl (0xfe000000))		      \
		 == htonl (0xfc000000))
#endif

#ifndef IN6_IS_ADDR_6TO4
	#define IN6_IS_ADDR_6TO4(a) \
		((((uint32_t *) (a))[0] & htonl (0xffff0000))		      \
		 == htonl (0x20020000))
#endif

#ifndef IN6_IS_ADDR_TEREDO
	#define IN6_IS_ADDR_TEREDO(a) \
		(((uint32_t *) (a))[0] == htonl (0x20020000))
#endif

#ifndef IN6_IS_ADDR_TEREDO_LEGACY
	#define IN6_IS_ADDR_TEREDO_LEGACY(a) \
		(((uint32_t *) (a))[0] == htonl (0x3ffe831f))
#endif


/* This causes Linux to use the BSD definition of the TCP and UDP header fields */
#ifndef __FAVOR_BSD
	#define __FAVOR_BSD
#endif
