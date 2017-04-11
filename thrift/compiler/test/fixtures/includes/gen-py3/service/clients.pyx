#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
from libcpp.memory cimport shared_ptr, make_shared, unique_ptr, make_unique
from libcpp.string cimport string
from libcpp cimport bool as cbool
from cpython cimport bool as pbool
from libc.stdint cimport int8_t, int16_t, int32_t, int64_t
from libcpp.vector cimport vector as vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap
from cython.operator cimport dereference as deref, typeid
from cpython.ref cimport PyObject
from thrift.py3.client cimport py3_get_exception, cRequestChannel_ptr, makeClientWrapper
from folly cimport cFollyTry, cFollyUnit, c_unit
from libcpp.typeinfo cimport type_info
import thrift.py3.types
cimport thrift.py3.types
import thrift.py3.client
cimport thrift.py3.client
from folly.futures cimport bridgeFutureWith
from folly.executor cimport get_executor

import asyncio
import sys
import traceback

cimport service.types
import service.types
cimport module.types
import module.types
cimport includes.types
import includes.types

from service.clients_wrapper cimport cMyServiceAsyncClient, cMyServiceClientWrapper


cdef void MyService_query_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* future
):
    cdef object pyfuture = <object> future
    cdef cFollyUnit citem
    if result.hasException():
        try:
            result.exception().throwException()
        except Exception as ex:
            pyfuture.set_exception(ex)
    else:
        citem = c_unit;
        pyfuture.set_result(None)


cdef class MyService(thrift.py3.client.Client):

    def __cinit__(MyService self):
        loop = asyncio.get_event_loop()
        self._connect_future = loop.create_future()
        self._executor = get_executor()

    cdef const type_info* _typeid(MyService self):
        return &typeid(cMyServiceAsyncClient)

    @staticmethod
    cdef _service_MyService_set_client(MyService inst, shared_ptr[cMyServiceClientWrapper] c_obj):
        """So the class hierarchy talks to the correct pointer type"""
        inst._service_MyService_client = c_obj

    cdef _service_MyService_reset_client(MyService self):
        """So the class hierarchy resets the shared pointer up the chain"""
        self._service_MyService_client.reset()

    def __dealloc__(MyService self):
        if self._cRequestChannel or self._service_MyService_client:
            print('client was not cleaned up, use the context manager', file=sys.stderr)

    async def __aenter__(MyService self):
        await self._connect_future
        if self._cRequestChannel:
            MyService._service_MyService_set_client(
                self,
                makeClientWrapper[cMyServiceAsyncClient, cMyServiceClientWrapper](
                    self._cRequestChannel
                ),
            )
            self._cRequestChannel.reset()
        else:
            raise asyncio.InvalidStateError('Client context has been used already')
        return self

    async def __aexit__(MyService self, *exc):
        self._check_connect_future()
        loop = asyncio.get_event_loop()
        future = loop.create_future()
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._service_MyService_client).disconnect(),
            closed_MyService_py3_client_callback,
            <PyObject *>future
        )
        # To break any future usage of this client
        badfuture = loop.create_future()
        badfuture.set_exception(asyncio.InvalidStateError('Client Out of Context'))
        badfuture.exception()
        self._connect_future = badfuture
        await future
        self._service_MyService_reset_client()

    async def query(
            MyService self,
            arg_s,
            arg_i):
        self._check_connect_future()
        loop = asyncio.get_event_loop()
        future = loop.create_future()
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._service_MyService_client).query(
                deref((<module.types.MyStruct>arg_s).c_MyStruct),
                deref((<includes.types.Included>arg_i).c_Included),
            ),
            MyService_query_callback,
            <PyObject *> future
        )
        return await future



cdef void closed_MyService_py3_client_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* fut,
):
    cdef object pyfuture = <object> fut
    pyfuture.set_result(None)
