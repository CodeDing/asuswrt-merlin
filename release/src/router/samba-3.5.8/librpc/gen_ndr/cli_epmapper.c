/*
 * Unix SMB/CIFS implementation.
 * client auto-generated by pidl. DO NOT MODIFY!
 */

#include "includes.h"
#include "../librpc/gen_ndr/cli_epmapper.h"

struct rpccli_epm_Insert_state {
	struct epm_Insert orig;
	struct epm_Insert tmp;
	TALLOC_CTX *out_mem_ctx;
	NTSTATUS (*dispatch_recv)(struct tevent_req *req, TALLOC_CTX *mem_ctx);
};

static void rpccli_epm_Insert_done(struct tevent_req *subreq);

struct tevent_req *rpccli_epm_Insert_send(TALLOC_CTX *mem_ctx,
					  struct tevent_context *ev,
					  struct rpc_pipe_client *cli,
					  uint32_t _num_ents /* [in]  */,
					  struct epm_entry_t *_entries /* [in] [size_is(num_ents)] */,
					  uint32_t _replace /* [in]  */)
{
	struct tevent_req *req;
	struct rpccli_epm_Insert_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct rpccli_epm_Insert_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;
	state->dispatch_recv = cli->dispatch_recv;

	/* In parameters */
	state->orig.in.num_ents = _num_ents;
	state->orig.in.entries = _entries;
	state->orig.in.replace = _replace;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = cli->dispatch_send(state, ev, cli,
				    &ndr_table_epmapper,
				    NDR_EPM_INSERT,
				    &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, rpccli_epm_Insert_done, req);
	return req;
}

static void rpccli_epm_Insert_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct rpccli_epm_Insert_state *state = tevent_req_data(
		req, struct rpccli_epm_Insert_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = state->dispatch_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS rpccli_epm_Insert_recv(struct tevent_req *req,
				TALLOC_CTX *mem_ctx,
				uint32 *result)
{
	struct rpccli_epm_Insert_state *state = tevent_req_data(
		req, struct rpccli_epm_Insert_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possbile out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS rpccli_epm_Insert(struct rpc_pipe_client *cli,
			   TALLOC_CTX *mem_ctx,
			   uint32_t num_ents /* [in]  */,
			   struct epm_entry_t *entries /* [in] [size_is(num_ents)] */,
			   uint32_t replace /* [in]  */)
{
	struct epm_Insert r;
	NTSTATUS status;

	/* In parameters */
	r.in.num_ents = num_ents;
	r.in.entries = entries;
	r.in.replace = replace;

	status = cli->dispatch(cli,
				mem_ctx,
				&ndr_table_epmapper,
				NDR_EPM_INSERT,
				&r);

	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	if (NT_STATUS_IS_ERR(status)) {
		return status;
	}

	/* Return variables */

	/* Return result */
	return NT_STATUS_OK;
}

struct rpccli_epm_Delete_state {
	struct epm_Delete orig;
	struct epm_Delete tmp;
	TALLOC_CTX *out_mem_ctx;
	NTSTATUS (*dispatch_recv)(struct tevent_req *req, TALLOC_CTX *mem_ctx);
};

static void rpccli_epm_Delete_done(struct tevent_req *subreq);

struct tevent_req *rpccli_epm_Delete_send(TALLOC_CTX *mem_ctx,
					  struct tevent_context *ev,
					  struct rpc_pipe_client *cli,
					  uint32_t _num_ents /* [in]  */,
					  struct epm_entry_t *_entries /* [in] [size_is(num_ents)] */)
{
	struct tevent_req *req;
	struct rpccli_epm_Delete_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct rpccli_epm_Delete_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;
	state->dispatch_recv = cli->dispatch_recv;

	/* In parameters */
	state->orig.in.num_ents = _num_ents;
	state->orig.in.entries = _entries;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = cli->dispatch_send(state, ev, cli,
				    &ndr_table_epmapper,
				    NDR_EPM_DELETE,
				    &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, rpccli_epm_Delete_done, req);
	return req;
}

static void rpccli_epm_Delete_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct rpccli_epm_Delete_state *state = tevent_req_data(
		req, struct rpccli_epm_Delete_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = state->dispatch_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS rpccli_epm_Delete_recv(struct tevent_req *req,
				TALLOC_CTX *mem_ctx,
				uint32 *result)
{
	struct rpccli_epm_Delete_state *state = tevent_req_data(
		req, struct rpccli_epm_Delete_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possbile out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS rpccli_epm_Delete(struct rpc_pipe_client *cli,
			   TALLOC_CTX *mem_ctx,
			   uint32_t num_ents /* [in]  */,
			   struct epm_entry_t *entries /* [in] [size_is(num_ents)] */)
{
	struct epm_Delete r;
	NTSTATUS status;

	/* In parameters */
	r.in.num_ents = num_ents;
	r.in.entries = entries;

	status = cli->dispatch(cli,
				mem_ctx,
				&ndr_table_epmapper,
				NDR_EPM_DELETE,
				&r);

	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	if (NT_STATUS_IS_ERR(status)) {
		return status;
	}

	/* Return variables */

	/* Return result */
	return NT_STATUS_OK;
}

struct rpccli_epm_Lookup_state {
	struct epm_Lookup orig;
	struct epm_Lookup tmp;
	TALLOC_CTX *out_mem_ctx;
	NTSTATUS (*dispatch_recv)(struct tevent_req *req, TALLOC_CTX *mem_ctx);
};

static void rpccli_epm_Lookup_done(struct tevent_req *subreq);

struct tevent_req *rpccli_epm_Lookup_send(TALLOC_CTX *mem_ctx,
					  struct tevent_context *ev,
					  struct rpc_pipe_client *cli,
					  uint32_t _inquiry_type /* [in]  */,
					  struct GUID *_object /* [in] [ptr] */,
					  struct rpc_if_id_t *_interface_id /* [in] [ptr] */,
					  uint32_t _vers_option /* [in]  */,
					  struct policy_handle *_entry_handle /* [in,out] [ref] */,
					  uint32_t _max_ents /* [in]  */,
					  uint32_t *_num_ents /* [out] [ref] */,
					  struct epm_entry_t *_entries /* [out] [length_is(*num_ents),size_is(max_ents)] */)
{
	struct tevent_req *req;
	struct rpccli_epm_Lookup_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct rpccli_epm_Lookup_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;
	state->dispatch_recv = cli->dispatch_recv;

	/* In parameters */
	state->orig.in.inquiry_type = _inquiry_type;
	state->orig.in.object = _object;
	state->orig.in.interface_id = _interface_id;
	state->orig.in.vers_option = _vers_option;
	state->orig.in.entry_handle = _entry_handle;
	state->orig.in.max_ents = _max_ents;

	/* Out parameters */
	state->orig.out.entry_handle = _entry_handle;
	state->orig.out.num_ents = _num_ents;
	state->orig.out.entries = _entries;

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "rpccli_epm_Lookup_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = cli->dispatch_send(state, ev, cli,
				    &ndr_table_epmapper,
				    NDR_EPM_LOOKUP,
				    &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, rpccli_epm_Lookup_done, req);
	return req;
}

static void rpccli_epm_Lookup_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct rpccli_epm_Lookup_state *state = tevent_req_data(
		req, struct rpccli_epm_Lookup_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = state->dispatch_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */
	*state->orig.out.entry_handle = *state->tmp.out.entry_handle;
	*state->orig.out.num_ents = *state->tmp.out.num_ents;
	if ((*state->tmp.out.num_ents) > (state->tmp.in.max_ents)) {
		tevent_req_nterror(req, NT_STATUS_INVALID_NETWORK_RESPONSE);
		return;
	}
	memcpy(state->orig.out.entries, state->tmp.out.entries, (*state->tmp.out.num_ents) * sizeof(*state->orig.out.entries));

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS rpccli_epm_Lookup_recv(struct tevent_req *req,
				TALLOC_CTX *mem_ctx,
				uint32 *result)
{
	struct rpccli_epm_Lookup_state *state = tevent_req_data(
		req, struct rpccli_epm_Lookup_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possbile out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS rpccli_epm_Lookup(struct rpc_pipe_client *cli,
			   TALLOC_CTX *mem_ctx,
			   uint32_t inquiry_type /* [in]  */,
			   struct GUID *object /* [in] [ptr] */,
			   struct rpc_if_id_t *interface_id /* [in] [ptr] */,
			   uint32_t vers_option /* [in]  */,
			   struct policy_handle *entry_handle /* [in,out] [ref] */,
			   uint32_t max_ents /* [in]  */,
			   uint32_t *num_ents /* [out] [ref] */,
			   struct epm_entry_t *entries /* [out] [length_is(*num_ents),size_is(max_ents)] */)
{
	struct epm_Lookup r;
	NTSTATUS status;

	/* In parameters */
	r.in.inquiry_type = inquiry_type;
	r.in.object = object;
	r.in.interface_id = interface_id;
	r.in.vers_option = vers_option;
	r.in.entry_handle = entry_handle;
	r.in.max_ents = max_ents;

	status = cli->dispatch(cli,
				mem_ctx,
				&ndr_table_epmapper,
				NDR_EPM_LOOKUP,
				&r);

	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	if (NT_STATUS_IS_ERR(status)) {
		return status;
	}

	/* Return variables */
	*entry_handle = *r.out.entry_handle;
	*num_ents = *r.out.num_ents;
	if ((*r.out.num_ents) > (r.in.max_ents)) {
		return NT_STATUS_INVALID_NETWORK_RESPONSE;
	}
	memcpy(entries, r.out.entries, (*r.out.num_ents) * sizeof(*entries));

	/* Return result */
	return NT_STATUS_OK;
}

struct rpccli_epm_Map_state {
	struct epm_Map orig;
	struct epm_Map tmp;
	TALLOC_CTX *out_mem_ctx;
	NTSTATUS (*dispatch_recv)(struct tevent_req *req, TALLOC_CTX *mem_ctx);
};

static void rpccli_epm_Map_done(struct tevent_req *subreq);

struct tevent_req *rpccli_epm_Map_send(TALLOC_CTX *mem_ctx,
				       struct tevent_context *ev,
				       struct rpc_pipe_client *cli,
				       struct GUID *_object /* [in] [ptr] */,
				       struct epm_twr_t *_map_tower /* [in] [ptr] */,
				       struct policy_handle *_entry_handle /* [in,out] [ref] */,
				       uint32_t _max_towers /* [in]  */,
				       uint32_t *_num_towers /* [out] [ref] */,
				       struct epm_twr_p_t *_towers /* [out] [length_is(*num_towers),size_is(max_towers)] */)
{
	struct tevent_req *req;
	struct rpccli_epm_Map_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct rpccli_epm_Map_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;
	state->dispatch_recv = cli->dispatch_recv;

	/* In parameters */
	state->orig.in.object = _object;
	state->orig.in.map_tower = _map_tower;
	state->orig.in.entry_handle = _entry_handle;
	state->orig.in.max_towers = _max_towers;

	/* Out parameters */
	state->orig.out.entry_handle = _entry_handle;
	state->orig.out.num_towers = _num_towers;
	state->orig.out.towers = _towers;

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "rpccli_epm_Map_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = cli->dispatch_send(state, ev, cli,
				    &ndr_table_epmapper,
				    NDR_EPM_MAP,
				    &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, rpccli_epm_Map_done, req);
	return req;
}

static void rpccli_epm_Map_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct rpccli_epm_Map_state *state = tevent_req_data(
		req, struct rpccli_epm_Map_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = state->dispatch_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */
	*state->orig.out.entry_handle = *state->tmp.out.entry_handle;
	*state->orig.out.num_towers = *state->tmp.out.num_towers;
	if ((*state->tmp.out.num_towers) > (state->tmp.in.max_towers)) {
		tevent_req_nterror(req, NT_STATUS_INVALID_NETWORK_RESPONSE);
		return;
	}
	memcpy(state->orig.out.towers, state->tmp.out.towers, (*state->tmp.out.num_towers) * sizeof(*state->orig.out.towers));

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS rpccli_epm_Map_recv(struct tevent_req *req,
			     TALLOC_CTX *mem_ctx,
			     uint32 *result)
{
	struct rpccli_epm_Map_state *state = tevent_req_data(
		req, struct rpccli_epm_Map_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possbile out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS rpccli_epm_Map(struct rpc_pipe_client *cli,
			TALLOC_CTX *mem_ctx,
			struct GUID *object /* [in] [ptr] */,
			struct epm_twr_t *map_tower /* [in] [ptr] */,
			struct policy_handle *entry_handle /* [in,out] [ref] */,
			uint32_t max_towers /* [in]  */,
			uint32_t *num_towers /* [out] [ref] */,
			struct epm_twr_p_t *towers /* [out] [length_is(*num_towers),size_is(max_towers)] */)
{
	struct epm_Map r;
	NTSTATUS status;

	/* In parameters */
	r.in.object = object;
	r.in.map_tower = map_tower;
	r.in.entry_handle = entry_handle;
	r.in.max_towers = max_towers;

	status = cli->dispatch(cli,
				mem_ctx,
				&ndr_table_epmapper,
				NDR_EPM_MAP,
				&r);

	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	if (NT_STATUS_IS_ERR(status)) {
		return status;
	}

	/* Return variables */
	*entry_handle = *r.out.entry_handle;
	*num_towers = *r.out.num_towers;
	if ((*r.out.num_towers) > (r.in.max_towers)) {
		return NT_STATUS_INVALID_NETWORK_RESPONSE;
	}
	memcpy(towers, r.out.towers, (*r.out.num_towers) * sizeof(*towers));

	/* Return result */
	return NT_STATUS_OK;
}

struct rpccli_epm_LookupHandleFree_state {
	struct epm_LookupHandleFree orig;
	struct epm_LookupHandleFree tmp;
	TALLOC_CTX *out_mem_ctx;
	NTSTATUS (*dispatch_recv)(struct tevent_req *req, TALLOC_CTX *mem_ctx);
};

static void rpccli_epm_LookupHandleFree_done(struct tevent_req *subreq);

struct tevent_req *rpccli_epm_LookupHandleFree_send(TALLOC_CTX *mem_ctx,
						    struct tevent_context *ev,
						    struct rpc_pipe_client *cli,
						    struct policy_handle *_entry_handle /* [in,out] [ref] */)
{
	struct tevent_req *req;
	struct rpccli_epm_LookupHandleFree_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct rpccli_epm_LookupHandleFree_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;
	state->dispatch_recv = cli->dispatch_recv;

	/* In parameters */
	state->orig.in.entry_handle = _entry_handle;

	/* Out parameters */
	state->orig.out.entry_handle = _entry_handle;

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "rpccli_epm_LookupHandleFree_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = cli->dispatch_send(state, ev, cli,
				    &ndr_table_epmapper,
				    NDR_EPM_LOOKUPHANDLEFREE,
				    &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, rpccli_epm_LookupHandleFree_done, req);
	return req;
}

static void rpccli_epm_LookupHandleFree_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct rpccli_epm_LookupHandleFree_state *state = tevent_req_data(
		req, struct rpccli_epm_LookupHandleFree_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = state->dispatch_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */
	*state->orig.out.entry_handle = *state->tmp.out.entry_handle;

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS rpccli_epm_LookupHandleFree_recv(struct tevent_req *req,
					  TALLOC_CTX *mem_ctx,
					  uint32 *result)
{
	struct rpccli_epm_LookupHandleFree_state *state = tevent_req_data(
		req, struct rpccli_epm_LookupHandleFree_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possbile out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS rpccli_epm_LookupHandleFree(struct rpc_pipe_client *cli,
				     TALLOC_CTX *mem_ctx,
				     struct policy_handle *entry_handle /* [in,out] [ref] */)
{
	struct epm_LookupHandleFree r;
	NTSTATUS status;

	/* In parameters */
	r.in.entry_handle = entry_handle;

	status = cli->dispatch(cli,
				mem_ctx,
				&ndr_table_epmapper,
				NDR_EPM_LOOKUPHANDLEFREE,
				&r);

	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	if (NT_STATUS_IS_ERR(status)) {
		return status;
	}

	/* Return variables */
	*entry_handle = *r.out.entry_handle;

	/* Return result */
	return NT_STATUS_OK;
}

struct rpccli_epm_InqObject_state {
	struct epm_InqObject orig;
	struct epm_InqObject tmp;
	TALLOC_CTX *out_mem_ctx;
	NTSTATUS (*dispatch_recv)(struct tevent_req *req, TALLOC_CTX *mem_ctx);
};

static void rpccli_epm_InqObject_done(struct tevent_req *subreq);

struct tevent_req *rpccli_epm_InqObject_send(TALLOC_CTX *mem_ctx,
					     struct tevent_context *ev,
					     struct rpc_pipe_client *cli,
					     struct GUID *_epm_object /* [in] [ref] */)
{
	struct tevent_req *req;
	struct rpccli_epm_InqObject_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct rpccli_epm_InqObject_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;
	state->dispatch_recv = cli->dispatch_recv;

	/* In parameters */
	state->orig.in.epm_object = _epm_object;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = cli->dispatch_send(state, ev, cli,
				    &ndr_table_epmapper,
				    NDR_EPM_INQOBJECT,
				    &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, rpccli_epm_InqObject_done, req);
	return req;
}

static void rpccli_epm_InqObject_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct rpccli_epm_InqObject_state *state = tevent_req_data(
		req, struct rpccli_epm_InqObject_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = state->dispatch_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS rpccli_epm_InqObject_recv(struct tevent_req *req,
				   TALLOC_CTX *mem_ctx,
				   uint32 *result)
{
	struct rpccli_epm_InqObject_state *state = tevent_req_data(
		req, struct rpccli_epm_InqObject_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possbile out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS rpccli_epm_InqObject(struct rpc_pipe_client *cli,
			      TALLOC_CTX *mem_ctx,
			      struct GUID *epm_object /* [in] [ref] */)
{
	struct epm_InqObject r;
	NTSTATUS status;

	/* In parameters */
	r.in.epm_object = epm_object;

	status = cli->dispatch(cli,
				mem_ctx,
				&ndr_table_epmapper,
				NDR_EPM_INQOBJECT,
				&r);

	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	if (NT_STATUS_IS_ERR(status)) {
		return status;
	}

	/* Return variables */

	/* Return result */
	return NT_STATUS_OK;
}

struct rpccli_epm_MgmtDelete_state {
	struct epm_MgmtDelete orig;
	struct epm_MgmtDelete tmp;
	TALLOC_CTX *out_mem_ctx;
	NTSTATUS (*dispatch_recv)(struct tevent_req *req, TALLOC_CTX *mem_ctx);
};

static void rpccli_epm_MgmtDelete_done(struct tevent_req *subreq);

struct tevent_req *rpccli_epm_MgmtDelete_send(TALLOC_CTX *mem_ctx,
					      struct tevent_context *ev,
					      struct rpc_pipe_client *cli,
					      uint32_t _object_speced /* [in]  */,
					      struct GUID *_object /* [in] [ptr] */,
					      struct epm_twr_t *_tower /* [in] [ptr] */)
{
	struct tevent_req *req;
	struct rpccli_epm_MgmtDelete_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct rpccli_epm_MgmtDelete_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;
	state->dispatch_recv = cli->dispatch_recv;

	/* In parameters */
	state->orig.in.object_speced = _object_speced;
	state->orig.in.object = _object;
	state->orig.in.tower = _tower;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = cli->dispatch_send(state, ev, cli,
				    &ndr_table_epmapper,
				    NDR_EPM_MGMTDELETE,
				    &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, rpccli_epm_MgmtDelete_done, req);
	return req;
}

static void rpccli_epm_MgmtDelete_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct rpccli_epm_MgmtDelete_state *state = tevent_req_data(
		req, struct rpccli_epm_MgmtDelete_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = state->dispatch_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS rpccli_epm_MgmtDelete_recv(struct tevent_req *req,
				    TALLOC_CTX *mem_ctx,
				    uint32 *result)
{
	struct rpccli_epm_MgmtDelete_state *state = tevent_req_data(
		req, struct rpccli_epm_MgmtDelete_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possbile out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS rpccli_epm_MgmtDelete(struct rpc_pipe_client *cli,
			       TALLOC_CTX *mem_ctx,
			       uint32_t object_speced /* [in]  */,
			       struct GUID *object /* [in] [ptr] */,
			       struct epm_twr_t *tower /* [in] [ptr] */)
{
	struct epm_MgmtDelete r;
	NTSTATUS status;

	/* In parameters */
	r.in.object_speced = object_speced;
	r.in.object = object;
	r.in.tower = tower;

	status = cli->dispatch(cli,
				mem_ctx,
				&ndr_table_epmapper,
				NDR_EPM_MGMTDELETE,
				&r);

	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	if (NT_STATUS_IS_ERR(status)) {
		return status;
	}

	/* Return variables */

	/* Return result */
	return NT_STATUS_OK;
}

struct rpccli_epm_MapAuth_state {
	struct epm_MapAuth orig;
	struct epm_MapAuth tmp;
	TALLOC_CTX *out_mem_ctx;
	NTSTATUS (*dispatch_recv)(struct tevent_req *req, TALLOC_CTX *mem_ctx);
};

static void rpccli_epm_MapAuth_done(struct tevent_req *subreq);

struct tevent_req *rpccli_epm_MapAuth_send(TALLOC_CTX *mem_ctx,
					   struct tevent_context *ev,
					   struct rpc_pipe_client *cli)
{
	struct tevent_req *req;
	struct rpccli_epm_MapAuth_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct rpccli_epm_MapAuth_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;
	state->dispatch_recv = cli->dispatch_recv;

	/* In parameters */

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = cli->dispatch_send(state, ev, cli,
				    &ndr_table_epmapper,
				    NDR_EPM_MAPAUTH,
				    &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, rpccli_epm_MapAuth_done, req);
	return req;
}

static void rpccli_epm_MapAuth_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct rpccli_epm_MapAuth_state *state = tevent_req_data(
		req, struct rpccli_epm_MapAuth_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = state->dispatch_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS rpccli_epm_MapAuth_recv(struct tevent_req *req,
				 TALLOC_CTX *mem_ctx,
				 uint32 *result)
{
	struct rpccli_epm_MapAuth_state *state = tevent_req_data(
		req, struct rpccli_epm_MapAuth_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possbile out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS rpccli_epm_MapAuth(struct rpc_pipe_client *cli,
			    TALLOC_CTX *mem_ctx)
{
	struct epm_MapAuth r;
	NTSTATUS status;

	/* In parameters */

	status = cli->dispatch(cli,
				mem_ctx,
				&ndr_table_epmapper,
				NDR_EPM_MAPAUTH,
				&r);

	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	if (NT_STATUS_IS_ERR(status)) {
		return status;
	}

	/* Return variables */

	/* Return result */
	return NT_STATUS_OK;
}

