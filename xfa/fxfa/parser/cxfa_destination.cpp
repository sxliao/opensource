// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_destination.h"

#include <memory>

#include "fxjs/xfa/cjx_node.h"

namespace {

const CXFA_Node::AttributeData kDestinationAttributeData[] = {
    {XFA_Attribute::Desc, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Lock, XFA_AttributeType::Integer, (void*)0},
};

}  // namespace

CXFA_Destination::CXFA_Destination(CXFA_Document* doc, XFA_PacketType packet)
    : CXFA_Node(doc,
                packet,
                XFA_XDPPACKET_Config,
                XFA_ObjectType::ContentNode,
                XFA_Element::Destination,
                {},
                kDestinationAttributeData,
                std::make_unique<CJX_Node>(this)) {}

CXFA_Destination::~CXFA_Destination() = default;
